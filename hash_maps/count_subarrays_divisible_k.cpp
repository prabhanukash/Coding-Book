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
  mp[0] = 1;
  int ans = 0;
  int prefSum = 0;
  for (int i = 0; i < n; i++)
  {
    prefSum += arr[i];

    int rem = prefSum % k;
    /*
        we can't do modulo for negatives. so add + k  to make remainder positive
        as k*n+y + k - k => k*(n-1) + (k-y);
     */
    if (rem < 0)
      rem += k;
    ans += mp[rem];
    mp[rem]++;
  }
  cout << ans << '\n';
  return 0;
}