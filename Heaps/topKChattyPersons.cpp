#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include <regex>

using namespace std;

// Struct to store person and word count
struct PersonWordCount {
    string name;
    int wordCount;
    
    bool operator<(const PersonWordCount &other) const {
        return wordCount > other.wordCount; // Min-heap based on word count
    }
};

// Function to count words in a message
int countWords(const string &message) {
    regex wordRegex(R"(\b\w+\b)");
    auto wordsBegin = sregex_iterator(message.begin(), message.end(), wordRegex);
    auto wordsEnd = sregex_iterator();
    return distance(wordsBegin, wordsEnd);
}

// Function to find top k chatty persons
vector<pair<string, int>> topKChattyPersons(const vector<string> &chatLog, int k) {
    unordered_map<string, int> wordCounts;
    
    for (const string &line : chatLog) {
        size_t start = line.find('<');
        size_t end = line.find('>');
        if (start != string::npos && end != string::npos && end > start) {
            string name = line.substr(start + 1, end - start - 1);
            string message = line.substr(end + 1);
            wordCounts[name] += countWords(message);
        }
    }
    priority_queue<PersonWordCount> minHeap;
    for (const auto &entry : wordCounts) {
        minHeap.push({entry.first, entry.second});
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    vector<pair<string, int>> result;
    while (!minHeap.empty()) {
        result.push_back({minHeap.top().name, minHeap.top().wordCount});
        minHeap.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<string> chatLog = {
        "<Jake>Hello!!There",
        "<Andrew>How Are!! You?",
        "<Jake>What's up?",
        "<Andrew>Not much, you?",
        "<Jake>Just working.",
        "<Andrew>Same here."
    };
        int k = 2;
        vector<pair<string, int>> topK = topKChattyPersons(chatLog, k);
        
        cout << "Top " << k << " chatty persons:" << endl;
        for (const auto &entry : topK) {
            cout << entry.first << ": " << entry.second << " words" << endl;
        }
    return 0;
}

