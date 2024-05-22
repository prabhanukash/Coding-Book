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

Node *mergeTwoSortedLL(Node *head1, Node *head2)
{
  Node *head = NULL, *tmp = NULL;
  while (head1 and head2)
  {
    if (head1->data <= head2->data)
    {
      if (head)
      {
        tmp->next = head1;
        tmp = tmp->next;
      }
      else
      {
        head = head1;
        tmp = head;
      }
      head1 = head1->next;
    }
    else
    {
      if (head)
      {
        tmp->next = head2;
        head2 = head2->next;
        tmp = tmp->next;
      }
      else
      {
        head = head2;
        tmp = head;
      }
    }
  }
  while (head1)
  {
    tmp->next = head1;
    head1 = head1->next;
  }
  while (head2)
  {
    tmp->next = head2;
    head2 = head2->next;
  }
  return head;
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
  head2->next = new Node(4);
  head2->next->next = new Node(6);
  
  printLL(mergeTwoSortedLL(head1, head2));
  return 0;
}