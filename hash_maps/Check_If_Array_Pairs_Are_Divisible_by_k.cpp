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

  for (int i = 0; i < n; i++)
  {
    int rem = arr[i] % k;
    mp[rem]++;
  }
  for (int val : arr)
  {
    int rem = val % k;
    if (rem == 0)
    {
      if (mp[rem] % 2)
      {
        cout << "False\n";
        return 0;
      }
    }
    else if (2 * rem == k)
    {
      if (mp[rem] % 2)
      {
        cout << "False\n";
        return 0;
      }
    }
    else
    {
      if (mp[rem] != mp[k - rem])
      {
        cout << "False\n";
        return 0;
      }
    }
  }
  cout << "True" << '\n';
  return 0;
}