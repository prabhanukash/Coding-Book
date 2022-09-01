#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  string str1, str2;
  cin >> str1 >> str2;
  int n = str1.size();
  int m = str2.size();
  int k;
  cin >> k;
  if (n != m)
  {
    cout << "False\n";
    return 0;
  }
  unordered_map<char, int> mp;

  for (int i = 0; i < n; i++)
    mp[str1[i]]++;

  for (int i = 0; i < n; i++)
  {
    if (mp.count(str2[i]))
    {
      mp[str2[i]]--;
    }
  }
  int ans = 0;
  for (auto i : mp)
  {
    ans += i.second;
  }
  if (ans > k)
  {
    cout << "NO\n";
  }
  else
    cout << "YES\n";

  return 0;
}