#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>
#include <vector>

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

public:
	Trie() : root(make_shared<TrieNode>()) {}
	void insert(const string &word)
	{
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
	string getLongestCommonPrefix()
	{
		string lcp("");
		shared_ptr<TrieNode> current = root;
		while (current and current->isEndOfWord == false and current->children.size() == 1)
		{
			auto it = current->children.begin();
			lcp += it->first;
			current = it->second;
		}
		return lcp;
	}
};

int main()
{
	Trie trie;
	// vector<string> strs = {"flower", "flow", "flight"};
	// vector<string> strs = {"dog", "racecar", "car"};
	vector<string> strs = {"", "b"};
	for (string str : strs)
		trie.insert(str);
	cout << trie.getLongestCommonPrefix() << endl;
}