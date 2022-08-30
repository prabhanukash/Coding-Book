#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int> &arr)
{
  int n = arr.size();
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      int sum = 0;
      for (int k = i; k <= j; k++)
      {
        cout << arr[k] << ' ';
        sum += arr[k];
      }
      cout << '\n';
      ans = max(ans, sum);
    }
  }
  return ans;
}
int kedanes(vector<int> &arr)
{
  int n = arr.size();
  int lcl_mx = 0;
  int gbl_mx = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    lcl_mx = max(arr[i], lcl_mx + arr[i]);
    gbl_mx = max(gbl_mx, lcl_mx);
  }
  return gbl_mx;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  // cout << maxSubArraySum(arr) << '\n';
  cout << kedanes(arr) << '\n';
  return 0;
}