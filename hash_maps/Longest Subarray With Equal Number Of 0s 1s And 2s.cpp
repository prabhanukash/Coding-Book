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
  int cnt0 = 0;
  int cnt1 = 0;
  int cnt2 = 0;
  int delta1 = cnt1 - cnt0;
  int delta2 = cnt2 - cnt1;
  string str = to_string(delta2) + "#" + to_string(delta1);
  map<string, int> mp;
  mp[str] = -1;
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int val;
    cin >> val;
    if (val == 0)
      cnt0++;
    else if (val == 1)
      cnt1++;
    else
      cnt2++;
    delta1 = cnt1 - cnt0;
    delta2 = cnt2 - cnt1;
    string str = to_string(delta2) + "#" + to_string(delta1);
    if (mp.count(str))
    {
      int idx = mp[str];
      ans = max(ans, i - idx);
    }
    else
      mp[str] = i;
  }
  cout << ans << '\n';
  return 0;
}