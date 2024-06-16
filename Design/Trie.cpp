#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    unordered_map<char, shared_ptr<TrieNode>> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie
{
private:
    shared_ptr<TrieNode> root;

    bool _delete(shared_ptr<TrieNode> current, const string &word, int depth)
    {
        if (!current)
            return false;

        if (depth == word.size())
        {
            if (!current->isEndOfWord)
                return false;
            current->isEndOfWord = false;
            return current->children.empty();
        }

        char ch = word[depth];
        if (!_delete(current->children[ch], word, depth + 1))
            return false;

        current->children.erase(ch);
        return !current->isEndOfWord && current->children.empty();
    }

    vector<string> _getPrefixes(shared_ptr<TrieNode> current, const string &prefix) const
    {
        vector<string> result;
        if (!current)
        {
            return result;
        }
        if (current->isEndOfWord)
        {
            result.push_back(prefix);
        }
        for (const auto &pair : current->children)
        {
            vector<string> childPrefixes = _getPrefixes(pair.second, prefix + pair.first);
            result.insert(result.end(), childPrefixes.begin(), childPrefixes.end());
        }
        return result;
    }

public:
    Trie() : root(make_shared<TrieNode>()) {}

    void insert(const string &word)
    {
        if (word.empty())
            throw invalid_argument("Cannot insert empty string");
            
        shared_ptr<TrieNode> current = root;
        for (char ch : word)
        {
            if (!current->children[ch])
            {
                current->children[ch] = make_shared<TrieNode>();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    bool search(const string &word) const
    {
        if (word.empty())
            return false;
        shared_ptr<TrieNode> current = root;
        for (char ch : word)
        {
            if (!current->children[ch])
                return false;
            current = current->children[ch];
        }
        return current->isEndOfWord;
    }

    vector<string> startsWith(const string &prefix) const
    {
        if (prefix.empty())
            return {};

        shared_ptr<TrieNode> current = root;
        for (char ch : prefix)
        {
            if (!current->children[ch])
                return {};
            current = current->children[ch];
        }
        return _getPrefixes(current, prefix);
    }

    void remove(const string &word)
    {
        if (word.empty())
            throw invalid_argument("Cannot remove empty string");
        _delete(root, word, 0);
    }
};

int main()
{   
    Trie trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");

    cout << "Searching 'apple': " << trie.search("apple") << endl;   // true
    cout << "Searching 'app': " << trie.search("app") << endl;       // true
    cout << "Searching 'ban': " << trie.search("ban") << endl;       // false
    cout << "Searching 'banana': " << trie.search("banana") << endl; // true
    cout << "Prefix 'app': ";
    auto appPrefixes = trie.startsWith("app");
    for (const auto &prefix : appPrefixes)
    {
        cout << prefix << " ";
    }
    cout << endl;

    cout << "Prefix 'ban': ";
    auto banPrefixes = trie.startsWith("ban");
    for (const auto &prefix : banPrefixes)
    {
        cout << prefix << " ";
    }
    cout << endl;

    cout << "Prefix 'bae': ";
    auto baePrefixes = trie.startsWith("bae");
    for (const auto &prefix : baePrefixes)
    {
        cout << prefix << " ";
    }
    cout << endl;

    return 0;
}