#include <algorithm>
#include <atomic>
#include <chrono>
#include <iostream>
#include <memory>
#include <mutex>
#include <shared_mutex>
#include <stdexcept>
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// User Class
class User {
public:
  User(string name, string profession)
      : name_(move(name)), profession_(move(profession)) {}

  const string &getName() const { return name_; }
  const string &getProfession() const { return profession_; }

  void subscribeToTopics(const vector<string> &topics) {
    unique_lock<shared_mutex> lock(mutex_);
    for (const auto &topic : topics) {
      subscribedTopics_.insert(topic);
    }
  }

  void unsubscribeFromTopics(const vector<string> &topics) {
    unique_lock<shared_mutex> lock(mutex_);
    for (const auto &topic : topics) {
      subscribedTopics_.erase(topic);
    }
  }

  bool isSubscribedTo(const string &topic) const {
    shared_lock<shared_mutex> lock(mutex_);
    return subscribedTopics_.find(topic) != subscribedTopics_.end();
  }

private:
  string name_;
  string profession_;
  unordered_set<string> subscribedTopics_;
  mutable shared_mutex mutex_;
};
// Answer Class
class Answer {
public:
  Answer(string content, shared_ptr<User> author)
      : id_(nextId_++), content_(move(content)), author_(move(author)),
        timestamp_(chrono::system_clock::now()) {}

  uint64_t getId() const { return id_; }
  const string &getContent() const { return content_; }
  shared_ptr<User> getAuthor() const { return author_; }
  chrono::system_clock::time_point getTimestamp() const { return timestamp_; }
  int getVotes() const { return votes_; }

  void upvote() { ++votes_; }

private:
  static atomic<uint64_t> nextId_;
  uint64_t id_;
  string content_;
  shared_ptr<User> author_;
  chrono::system_clock::time_point timestamp_;
  atomic<int> votes_{0};
};

atomic<uint64_t> Answer::nextId_{0};

// Question Class
class Question {
public:
  Question(string content, shared_ptr<User> author, vector<string> topics)
      : id_(nextId_++), content_(move(content)), author_(move(author)),
        topics_(move(topics)), timestamp_(chrono::system_clock::now()) {}

  uint64_t getId() const { return id_; }
  const string &getContent() const { return content_; }
  shared_ptr<User> getAuthor() const { return author_; }
  const vector<string> &getTopics() const { return topics_; }
  chrono::system_clock::time_point getTimestamp() const { return timestamp_; }
  int getVotes() const { return votes_; }

  void upvote() { ++votes_; }

  void addAnswer(shared_ptr<Answer> answer) {
    lock_guard<mutex> lock(mutex_);
    answers_.push_back(move(answer));
  }

  vector<shared_ptr<Answer>> getAnswers() const {
    lock_guard<mutex> lock(mutex_);
    return answers_;
  }

private:
  static atomic<uint64_t> nextId_;
  uint64_t id_;
  string content_;
  shared_ptr<User> author_;
  vector<string> topics_;
  chrono::system_clock::time_point timestamp_;
  atomic<int> votes_{0};
  vector<shared_ptr<Answer>> answers_;
  mutable mutex mutex_;
};

atomic<uint64_t> Question::nextId_{0};

// FlipkartOverflow Class
class FlipkartOverflow {
public:
  void userSignup(const string &name, const string &profession) {
    lock_guard<mutex> lock(usersMutex_);
    if (users_.find(name) != users_.end()) {
      throw runtime_error("User already exists");
    }
    users_[name] = make_shared<User>(name, profession);
    logAction(name + " Signup successful!");
  }

  void login(const string &name) {
    lock_guard<mutex> lock(usersMutex_);
    auto it = users_.find(name);
    if (it == users_.end()) {
      throw runtime_error("User not found");
    }
    loggedInUser_ = it->second;
    logAction("Login successful! for " + name);
  }

  void logout() {
    if (loggedInUser_) {
      logAction(loggedInUser_->getName() + " logged out.");
      loggedInUser_.reset();
    } else {
      logAction("No user logged in.");
    }
  }

  void subscribe(const vector<string> &topics) {
    checkLoggedIn();
    loggedInUser_->subscribeToTopics(topics);
    logAction(loggedInUser_->getName() +
              " has subscribed to topics: " + topicsToString(topics));
  }

  void unsubscribe(const vector<string> &topics) {
    checkLoggedIn();
    loggedInUser_->unsubscribeFromTopics(topics);
    logAction(loggedInUser_->getName() +
              " has unsubscribed from topics: " + topicsToString(topics));
  }

  void addQuestion(const string &content, const vector<string> &topics) {
    checkLoggedIn();
    auto question = make_shared<Question>(content, loggedInUser_, topics);
    lock_guard<mutex> lock(questionsMutex_);
    questions_.push_back(move(question));
    logAction(loggedInUser_->getName() + " added a new question: \"" + content +
              "\" Topics: " + topicsToString(topics));
  }

  void answerQuestion(uint64_t questionId, const string &content) {
    checkLoggedIn();
    auto question = findQuestionById(questionId);
    if (!question) {
      throw runtime_error("Question not found");
    }
    if (!isUserSubscribedToQuestionTopics(question)) {
      throw runtime_error(
          "You are not subscribed to the topic of this question");
    }
    auto answer = make_shared<Answer>(content, loggedInUser_);
    question->addAnswer(move(answer));
    logAction(loggedInUser_->getName() + " answered Question ID " +
              to_string(questionId));
  }

  void upvoteQuestion(uint64_t questionId) {
    checkLoggedIn();
    auto question = findQuestionById(questionId);
    if (!question) {
      throw runtime_error("Question not found");
    }
    if (!isUserSubscribedToQuestionTopics(question)) {
      throw runtime_error(
          "You are not subscribed to the topic of this question");
    }
    question->upvote();
    logAction(loggedInUser_->getName() + " upvoted Question ID " +
              to_string(questionId));
  }

  void upvoteAnswer(uint64_t questionId, uint64_t answerId) {
    checkLoggedIn();
    auto question = findQuestionById(questionId);
    if (!question) {
      throw runtime_error("Question not found");
    }
    if (!isUserSubscribedToQuestionTopics(question)) {
      throw runtime_error(
          "You are not subscribed to the topic of this question");
    }
    auto answer = findAnswerById(question, answerId);
    if (!answer) {
      throw runtime_error("Answer not found");
    }
    answer->upvote();
    logAction(loggedInUser_->getName() + " upvoted Answer ID " +
              to_string(answerId) + " to Question ID " + to_string(questionId));
  }

  vector<shared_ptr<Question>> showFeed(const vector<string> *filter = nullptr,
                                        bool answeredOnly = false) const {
    lock_guard<mutex> lock(questionsMutex_);
    logAction(loggedInUser_->getName() + " is viewing the feed");
    vector<shared_ptr<Question>> filteredQuestions;
    for (const auto &question : questions_) {
      if (passFilter(question, filter, answeredOnly)) {
        filteredQuestions.push_back(question);
      }
    }
    sortQuestionsByVotes(filteredQuestions);
    return filteredQuestions;
  }

  shared_ptr<User> getLoggedInUser() const { return loggedInUser_; }

private:
  unordered_map<string, shared_ptr<User>> users_;
  mutable mutex usersMutex_;
  vector<shared_ptr<Question>> questions_;
  mutable mutex questionsMutex_;
  shared_ptr<User> loggedInUser_;

  void checkLoggedIn() const {
    if (!loggedInUser_) {
      throw runtime_error("You must be logged in to perform actions.");
    }
  }

  shared_ptr<Question> findQuestionById(uint64_t id) const {
    lock_guard<mutex> lock(questionsMutex_);
    auto it = find_if(questions_.begin(), questions_.end(),
                      [id](const auto &q) { return q->getId() == id; });
    return (it != questions_.end()) ? *it : nullptr;
  }

  shared_ptr<Answer> findAnswerById(const shared_ptr<Question> &question,
                                    uint64_t answerId) const {
    auto answers = question->getAnswers();
    auto it =
        find_if(answers.begin(), answers.end(),
                [answerId](const auto &a) { return a->getId() == answerId; });
    return (it != answers.end()) ? *it : nullptr;
  }

  bool isUserSubscribedToQuestionTopics(const shared_ptr<Question> &question) const {
    for (const auto &topic : question->getTopics()) {
      if (loggedInUser_->isSubscribedTo(topic)) {
        return true;
      }
    }
    return false;
  }

  bool passFilter(const shared_ptr<Question> &question,
                  const vector<string> *filter, bool answeredOnly) const {
    if (filter && !filter->empty()) {
      bool topicMatch = false;
      for (const auto &topic : *filter) {
        if (find(question->getTopics().begin(), question->getTopics().end(),
                 topic) != question->getTopics().end()) {
          topicMatch = true;
          break;
        }
      }
      if (!topicMatch) {
        return false;
      }
    }
    if (answeredOnly && question->getAnswers().empty()) {
      return false;
    }
    return true;
  }

  void sortQuestionsByVotes(vector<shared_ptr<Question>> &questions) const {
    sort(questions.begin(), questions.end(), [](const auto &a, const auto &b) {
      return a->getVotes() > b->getVotes();
    });
  }

  void logAction(const string &action) const {
    cout << "LOG: " << action << endl;
  }

  string topicsToString(const vector<string> &topics) const {
    string result;
    for (const auto &topic : topics) {
      result += topic + " ";
    }
    return result;
  }
};

// Demo function
void runDemo() {
  FlipkartOverflow platform;

  try {
    cout << "=== Flipkart Overflow Demo ===" << endl;

    // User Signup
    platform.userSignup("Sachin", "Developer");
    platform.userSignup("Rahul", "Data Scientist");
    platform.userSignup("Priya", "DevOps Engineer");

    // Login as Sachin
    platform.login("Sachin");

    // Subscribe to topics
    platform.subscribe({"java", "hadoop", "jdk"});

    // Ask Questions
    platform.addQuestion("What are new open source JDKs?", {"java", "jdk"});
    platform.addQuestion("Does Hadoop work on JDK 11?", {"hadoop", "jdk"});

    // Show Feed
    auto allQuestions = platform.showFeed();
    for (const auto &q : allQuestions) {
      cout << "- " << q->getContent() << " (Topics: ";
      for (const auto &topic : q->getTopics()) {
        cout << topic << " ";
      }
      cout << ")" << endl;
    }

    // Filter questions by topic
    vector<string> javaFilter = {"java"};
    auto javaQuestions = platform.showFeed(&javaFilter);
    cout << "Java questions:" << endl;
    for (const auto &q : javaQuestions) {
      cout << "- " << q->getContent() << endl;
    }

    // Logout and login as Rahul
    platform.logout();
    platform.login("Rahul");

    // Subscribe to different topics
    platform.subscribe({"hadoop", "machine-learning", "jdk"});

    // Answer a question
    try {
      platform.answerQuestion(
          0, "Yes, Hadoop works on JDK 11 with some configurations.");
    } catch (const exception &e) {
      cout << "Error: " << e.what() << endl;
    }

    // Upvote a question
    platform.upvoteQuestion(0);
    platform.upvoteAnswer(0, 0);

    // Show answered questions
    auto answeredQuestions = platform.showFeed(nullptr, true);

    if (answeredQuestions.empty()) {
      cout << "No answered questions to display for "
           << platform.getLoggedInUser()->getName() << endl;
    } else {
      for (const auto &q : answeredQuestions) {
        cout << "- " << q->getContent() << " (Votes: " << q->getVotes() << ")"
             << endl;
        auto answers = q->getAnswers();
        if (answers.empty()) {
          cout << "  No answers yet." << endl;
        } else {
          for (const auto &a : answers) {
            cout << "  Answer: " << a->getContent()
                 << " (Votes: " << a->getVotes() << ")" << endl;
          }
        }
      }
    }

    // Logout and login as Priya
    platform.logout();
    platform.login("Priya");

    // Subscribe to all topics
    platform.subscribe({"java", "hadoop", "jdk", "python", "machine-learning"});

    // Upvote an answer
    platform.upvoteAnswer(0, 0);

    // Add a new question
    platform.addQuestion("What are the best practices for ML model deployment?",
                         {"machine-learning", "python"});

    // Show final feed
    auto finalFeed = platform.showFeed();
    for (const auto &q : finalFeed) {
      cout << "- " << q->getContent() << " (Votes: " << q->getVotes() << ")"
           << endl;
      for (const auto &a : q->getAnswers()) {
        cout << "  Answer: " << a->getContent() << " (Votes: " << a->getVotes()
             << ")" << endl;
      }
    }

    // Logout
    platform.logout();

  } catch (const exception &e) {
    cerr << "Error: " << e.what() << endl;
  }
}

int main() {
  runDemo();
  return 0;
}
