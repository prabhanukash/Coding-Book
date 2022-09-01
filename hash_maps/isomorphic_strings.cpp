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
  if (n != m)
  {
    cout << "False\n";
    return 0;
  }
  unordered_map<char, char> mp;
  unordered_map<char, bool> mp1;
  for (int i = 0; i < n; i++)
  {
    char ch1 = str1[i];
    char ch2 = str2[i];
    if (mp.count(ch1))
    {
      if (mp[ch1] != ch2)
      {
        cout << "NO\n";
        return 0;
      }
    }
    else
    {
      if (mp1.count(ch2))
      {
        cout << "NO\n";
        return 0;
      }
      else
      {
        mp[str1[i]] = str2[i];
        mp1[str2[i]] = true;
      }
    }
  }
  cout << "YES\n";
  return 0;
}