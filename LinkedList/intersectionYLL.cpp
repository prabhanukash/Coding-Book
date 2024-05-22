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


Node *intersectionYNode(Node *head1, Node *head2)
{
  Node *ptr_1 = head1;
  Node *ptr_2 = head2;
  while (ptr_1 != ptr_2)
  {
    ptr_1 = ptr_1->next;
    ptr_2 = ptr_2->next;
    if (ptr_1 == NULL)
      ptr_1 = head2;
    if (ptr_2 == NULL)
      ptr_2 = head1;
  }
  return ptr_1;
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
  Node *head2 = new Node(2);
  head2->next = head1->next;
  cout<<intersectionYNode(head1, head2)->data << '\n';
  return 0;
}