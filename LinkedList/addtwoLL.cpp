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

void printLL(Node* head){
  Node *tmp = head;
  while(tmp){
    cout << tmp->data << ' ';
    tmp=tmp->next;
  }
  cout << '\n';
}
Node* sumOfLL(Node* l1, Node* l2){
  Node *dummyHead = new Node(0);
  Node *curr = dummyHead;
  int carry = 0;
  while (l1 != NULL || l2 != NULL || carry != 0)
  {
    int x = l1 ? l1->data : 0;
    int y = l2 ? l2->data : 0;
    int sum = carry + x + y;
    carry = sum / 10;
    curr->next = new Node(sum % 10);
    curr = curr->next;
    l1 = l1 ? l1->next : nullptr;
    l2 = l2 ? l2->next : nullptr;
  }
  printLL(dummyHead->next);
  return dummyHead->next;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Node *h1 = new Node(1);
  h1->next = new Node(2);
  h1->next->next = new Node(3);
  
  Node *h2 = new Node(1);
  h2->next = new Node(2);
  h2->next->next = new Node(3);

  sumOfLL(h1, h2);

  return 0;
}