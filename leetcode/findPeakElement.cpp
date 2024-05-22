#include <bits/stdc++.h>
using namespace std;
int findPeakPosition(int arr[], int n)
{
  if (n == 1)
    return 0;
  if (arr[0] >= arr[1])
    return 0;
  if (arr[n - 1] >= arr[n - 2])
    return n - 1;
  for (int i = 1; i < n; i++)
  {
    if (arr[i] >= arr[i - 1] and arr[i] >= arr[i + 1])
      return i;
  }
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
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << arr[findPeakPosition(arr, n)];
  return 0;
}