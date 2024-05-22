#include <bits/stdc++.h>
using namespace std;

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
  map<int, int> mp;
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int mn = arr[i];
    int mx = arr[i];
    for (int j = i + 1; j < n; j++)
    {
      mx = max(mx, arr[j]);
      mn = min(mn, arr[j]);
      if (mx - mn == j - i)
      {
        ans = max(ans, j - i + 1);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}