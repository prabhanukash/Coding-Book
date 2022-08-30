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
  vector<int> arr(n, 0);
  int q;
  cin >> q;
  while (q--)
  {
    int l, r;
    cin >> l >> r;
    if (r + 1 < n)
      arr[r + 1] -= 1;
    arr[l] += 1;
  }
  cout << arr[0] << ' ';
  for (int i = 1; i < n; i++)
  {
    arr[i] += arr[i - 1];
    cout << arr[i] << ' ';
  }
  return 0;
}