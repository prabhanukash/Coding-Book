#include <bits/stdc++.h>
using namespace std;
int totPaths = 0;
bool isSafe(int i, int j, int n, int m, vector<vector<bool>> &vis)
{
  return (i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == false);
}
void helper(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<bool>> &vis)
{
  if (i == n - 1 and j == m - 1)
  {
    totPaths++;
    return;
  }
  if (!isSafe(i, j, n, m, vis))
    return;

  vis[i][j] = true;
  if (i + 1 < n and grid[i + 1][j] == 0) // down
  {
    helper(i + 1, j, n, m, grid, vis);
  }
  if (j + 1 < m and grid[i][j + 1] == 0) // right
  {
    helper(i, j + 1, n, m, grid, vis);
  }
  if (i - 1 >= 0 and grid[i - 1][j] == 0) // up
  {
    helper(i - 1, j, n, m, grid, vis);
  }
  if (j - 1 >= 0 and grid[i][j - 1] == 0) // left
  {
    helper(i, j - 1, n, m, grid, vis);
  }
  vis[i][j] = false;
  return;
}
int countRatMaze(vector<vector<int>> &grid)
{
  int n = grid.size();
  int m = grid[0].size();
  totPaths = 0;
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  helper(0, 0, n, m, grid, vis);
  return totPaths;
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
        cin >> arr[i][j];
    }
    cout << countRatMaze(arr);
    return 0;
}