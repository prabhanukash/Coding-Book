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
  unordered_map<int, int> mp;
  unordered_map<int, int> left;
  int hfreq = 0;
  int s = 0;
  int e = 0;
  int len = e - s + 1;
  for (int i = 0; i < n; i++)
  {
    if (mp.count(arr[i]))
    {
      mp[arr[i]]++;
    }
    else
    {
      mp[arr[i]]++;
      left[arr[i]] = i;
    }
    if (hfreq < mp[arr[i]])
    {
      hfreq = mp[arr[i]];
      s = left[arr[i]];
      e = i;
      len = e - s + 1;
    }
    else if (hfreq == mp[arr[i]])
    {
      int clen = i - left[arr[i]] + 1;
      if (clen < len)
      {
        hfreq = mp[arr[i]];
        s = left[arr[i]];
        e = i;
        len = e - s + 1;
      }
    }
  }
  cout << arr[s] << '\n';
  cout << s << '\n';
  cout << e << '\n';
  return 0;
}