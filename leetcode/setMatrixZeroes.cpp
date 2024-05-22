#include <bits/stdc++.h>
using namespace std;
void setMatrixZeroes(vector<vector<int>> &arr)
{
  int n = arr.size();
  int m = arr[0].size();
  int col0 = 1;
  for (int i = 0; i < n; i++)
  {
    if (arr[i][0] == 0)
      col0 = 0;
    for (int j = 1; j < m; j++)
    {
      if (arr[i][j] == 0)
      {
        arr[0][j] = arr[i][0] = 0;
      }
    }
  }
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = m - 1; j >= 1; j--)
    {
      if (arr[0][j] == 0 or arr[i][0] == 0)
        arr[i][j] = 0;
    }
    if (col0 == 0)
      arr[i][0] = 0;
  }
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int n, m;
  cin >> n >> m;
  vector<vector<int>> arr(n, vector<int>(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }
  setMatrixZeroes(arr);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << arr[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}