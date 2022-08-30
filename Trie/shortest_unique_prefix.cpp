#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
  char data;
  bool isTerminal;
  unordered_map<char, Node *> children;
  int freq;
  Node(char d)
  {
    this->data = d;
    this->isTerminal = false;
    this->freq = 1;
  }
};
class Trie
{
public:
  Node *root;
  Trie()
  {
    root = new Node('\0');
  }
  void insert(string s)
  {
    Node *tmp = root;
    for (char ch : s)
    {
      if (tmp->children.count(ch))
      {
        tmp = tmp->children[ch];
        tmp->freq = tmp->freq + 1;
      }
      else
      {

        Node *n = new Node(ch);
        tmp->children[ch] = n;
        tmp = n;
      }
    }
    tmp->isTerminal = true;
  }

  void printShortestUniquePrefix(Node *root, string osf)
  {
    if (root == NULL)
      return;
    if (root->freq == 1 and root->data != '\0')
    {
      cout << osf << '\n';
      return;
    }
    for (auto i : root->children)
    {
      printShortestUniquePrefix(i.second, osf + i.first);
    }
  }
};
int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Trie t;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    string str;
    cin >> str;
    t.insert(str);
  }
  t.printShortestUniquePrefix(t.root, "");
  return 0;
}