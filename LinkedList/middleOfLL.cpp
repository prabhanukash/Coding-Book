#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
  int data;
  Node *next;
  Node(int d)
  {
    data = d;
    next = NULL;
  }
};
void printLL(Node *head)
{
  Node *tmp = head;
  while (tmp)
  {
    cout << tmp->data << ' ';
    tmp = tmp->next;
  }
  cout << '\n';
}

Node *middleOfLL(Node *head)
{
  Node *fst_ptr = head;
  Node *slw_ptr = head;

  while (fst_ptr and fst_ptr->next)
  {
    fst_ptr = fst_ptr->next->next;
    slw_ptr = slw_ptr->next;
  }
  return slw_ptr;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Node *head1 = new Node(1);
  head1->next = new Node(3);
  head1->next->next = new Node(5);
 
  cout<<middleOfLL(head1)->data << '\n';

  return 0;
}