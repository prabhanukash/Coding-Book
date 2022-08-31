#include <bits/stdc++.h>
using namespace std;

bool compare(map<char, int> &mp, map<char, int> &mp1)
{
  for (auto i : mp)
  {
    if (i.second != mp1[i.first])
      return false;
  }
  return true;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  string str;
  cin >> str;
  string pat;
  cin >> pat;
  int n = str.size();
  int k = pat.size();
  int ans = 0;
  vector<int> mp(26, 0), mp1(26, 0);
  for (char ch : pat)
    mp[ch - 'a']++;
  for (int i = 0; i < k; i++)
  {
    mp1[str[i] - 'a']++;
  }
  for (int i = k; i < n; i++)
  {
    if (mp == mp1)
      ans++;
    mp1[str[i] - 'a']++;
    mp1[str[i - k] - 'a']--;
  }
  cout << ans << '\n';
  return 0;
}