#include <bits/stdc++.h>
using namespace std;

int usingSorting(int arr[], int n, int k)
{

  sort(arr, arr + n);
  return arr[k - 1];
  /*
      TC: O(N*log(N))+O(1)
      SC:O(1)
   */
}
int usingMinHeap(int arr[], int n, int k)
{
  priority_queue<int> pq;
  for (int i = 0; i < n; i++)
    pq.push(-arr[i]);

  for (int i = 0; i < k - 1; i++)
  {
    pq.pop();
  }
  return -pq.top();
  /*
  TC:O(N)+(K-1)*log(N)
  SC:O(N)
   */
}

int usingMaxHeap(int arr[], int n, int k)
{

  priority_queue<int> pq;
  for (int i = 0; i < k; i++)
    pq.push(arr[i]);

  for (int i = k; i < n; i++)
  {
    if (pq.top() > arr[i])
    {
      pq.pop();
      pq.push(arr[i]);
    }
  }
  return pq.top();
  /*
   TC:O(K + (N-K)*log(K))
   SC:O(K)
    */
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  int arr[n];
  int k;
  cin >> k;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << usingSorting(arr, n, k) << '\n';
  cout << usingMinHeap(arr, n, k) << '\n';
  cout << usingMaxHeap(arr, n, k) << '\n';
  return 0;
}