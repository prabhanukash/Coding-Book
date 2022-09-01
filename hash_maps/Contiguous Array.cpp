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
  {
    cin >> arr[i];
    if (arr[i] == 0)
      arr[i] = -1;
  }
  map<int, int> mp;
  mp[0] = -1;
  int prefSum = 0;
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    prefSum += arr[i];
    if (mp.count(prefSum))
      ans = max(ans, i - mp[prefSum]);
    else
      mp[prefSum] = i;
  }
  cout << ans << '\n';
  return 0;
}