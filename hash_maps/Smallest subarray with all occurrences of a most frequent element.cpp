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
  unordered_map<int, int> mp, left, right;
  int ans = 0, key;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    if (mp.count(arr[i]))
    {
      right[arr[i]] = i;
    }
    else
    {
      left[arr[i]] = i;
      right[arr[i]] = i;
    }
    mp[arr[i]]++;
    if (ans < mp[arr[i]])
    {
      ans = mp[arr[i]];
      key = arr[i];
    }
  }
  cout << key << ' ' << ans << '\n';
  for (int i = left[key]; i <= right[key]; i++)
  {
    cout << arr[i] << ' ';
  }
  cout << '\n';

  return 0;
}