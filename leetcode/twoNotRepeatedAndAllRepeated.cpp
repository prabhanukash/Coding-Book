#include <bits/stdc++.h>
using namespace std;

pair<int, int> getTwoNumbers(int arr[], int n)
{
  pair<int, int> ans;
  int xor_val = 0;
  for (int i = 0; i < n; i++)
    xor_val ^= arr[i];
  int RMSB_val = xor_val & ~(xor_val - 1);
  int x = 0, y = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] & RMSB_val)
      x ^= arr[i];
    else
      y ^= arr[i];
  }
  ans = {x, y};
  return ans;
  /*
  TC:O(N)
  SC:O(1)
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
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  pair<int, int> ans = getTwoNumbers(arr, n);
  cout << ans.first << ' ' << ans.second << '\n';
  return 0;
}