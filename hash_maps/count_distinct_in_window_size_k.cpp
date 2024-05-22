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
  int k;
  cin >> k;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  map<int, int> mp;
  for (int i = 0; i < k; i++)
    mp[arr[i]]++;
  cout << mp.size() << ' ';
  for (int i = k; i < n; i++)
  {
    mp[arr[i - k]]--;
    if (mp[arr[i - k]] == 0)
    {
      mp.erase(arr[i - k]);
    }
    mp[arr[i]]++;
    cout << mp.size() << ' ';
  }
  cout << '\n';
  return 0;
}