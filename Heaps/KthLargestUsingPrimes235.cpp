#include <bits/stdc++.h>
using namespace std;
int finKthLargestWithNumbersFormedWith235(int k)
{
  priority_queue<int> pq;
  pq.push(-1);
  while (k > 0)
  {
    int t = pq.top();
    cout << t << '\n';
    pq.pop();
    pq.push(t * 2);
    pq.push(t * 3);
    pq.push(t * 5);
    k--;
  }
  return -pq.top();
  /*
  TC:K*log(K)
   */
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int k;
  cin >> k;
  cout << finKthLargestWithNumbersFormedWith235(k);
  return 0;
}