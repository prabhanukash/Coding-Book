#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;
  Node(int data)
  {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};
vector<vector<int>> printDiagonalOrderBt(Node *root)
{
  vector<vector<int>> ans;
  queue<Node *> q;
  q.push(root);
  while (q.size() != 0) // diagonal number
  {
    int sz = q.size();
    vector<int> trav;
    while (sz--) // each component
    {
      Node *node = q.front();
      q.pop();
      while (node != nullptr) // traversing
      {
        trav.push_back(node->data);
        if (node->left)
          q.push(node->left);
        node = node->right;
      }
    }
    ans.push_back(trav);
  }
  return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Node *root = new Node(8);
  root->left = new Node(3);
  root->right = new Node(10);
  root->left->left = new Node(1);
  root->left->right = new Node(6);
  root->right->right = new Node(14);
  root->right->right->left = new Node(13);
  root->left->right->left = new Node(4);
  root->left->right->right = new Node(7);
  vector<vector<int>> ans = printDiagonalOrderBt(root);
  for (auto vec : ans)
  {
    for (auto i : vec)
      cout << i << ' ';
    cout << '\n';
  }
  return 0;
}