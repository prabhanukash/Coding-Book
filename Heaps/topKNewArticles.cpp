#include <bits/stdc++.h>
using namespace std;

// Article class representing a news article
class Article
{
public:
    int id;
    string title;
    int popularity;

    Article() : id(0), title(""), popularity(0) {} // Default constructor

    Article(int id, string title, int popularity) : id(id), title(title), popularity(popularity) {}
};

// Comparator for the min-heap
struct Compare
{
    bool operator()(const Article &a, const Article &b)
    {
        return a.popularity > b.popularity;
    }
};

class NewsSystem
{
private:
    unordered_map<int, Article> articles;
    priority_queue<Article, vector<Article>, Compare> minHeap;
    int k;

public:
    NewsSystem(int k) : k(k) {}

    void addOrUpdateArticle(int id, const string &title, int popularity)
    {
        if (articles.find(id) != articles.end())
        {
            articles[id].popularity = popularity;
        }
        else
        {
            Article newArticle(id, title, popularity);
            articles[id] = newArticle;
        }

        minHeap.push(articles[id]);

        if (minHeap.size() > k)
        {
            minHeap.pop();
        }
    }

    vector<Article> getTopKArticles()
    {
        vector<Article> topK;
        priority_queue<Article, vector<Article>, Compare> tempHeap = minHeap;

        while (!tempHeap.empty())
        {
            topK.push_back(tempHeap.top());
            tempHeap.pop();
        }

        reverse(topK.begin(), topK.end());
        return topK;
    }
};

int main()
{
    NewsSystem newsSystem(3);

    newsSystem.addOrUpdateArticle(1, "Article 1", 10);
    newsSystem.addOrUpdateArticle(2, "Article 2", 20);
    newsSystem.addOrUpdateArticle(3, "Article 3", 5);
    newsSystem.addOrUpdateArticle(4, "Article 4", 25);

    vector<Article> topK = newsSystem.getTopKArticles();

    cout << "Top " << 3 << " articles:" << endl;
    for (const auto &article : topK)
    {
        cout << "ID: " << article.id << ", Title: " << article.title << ", Popularity: " << article.popularity << endl;
    }

    return 0;
}
