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
Node* reverse(Node* head){
  Node* prev=nullptr;
  Node* curr=head;
  Node *next;
  while(curr){
    next=curr->next;
    curr->next=prev;
    prev = curr;
    curr=next;
  }
  return prev;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    printLL(head);
    printLL(reverse(head));
    return 0;
}