#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int> &arr)
{
  int n = arr.size();
  int s = 0;
  int m = 0;
  int e = n - 1;
  while (m <= e)
  {
    switch (arr[m])
    {
    case 0:
      swap(arr[s], arr[m]);
      s++;
      m++;
      break;
    case 1:
      m++;
      break;
    case 2:
      swap(arr[m], arr[e]);
      e--;
      break;
    }
  }
 
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  sort012(arr);
  for (int i = 0; i < n; i++)
    cout << arr[i] << ' ';
  return 0;
}