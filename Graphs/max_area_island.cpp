#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int cnt = 0;

bool isSafe(vector<vector<int>> &adjMat, vector<vector<bool>> &visited, int x, int y)
{
  int n = adjMat.size();
  int m = adjMat[0].size();
  return (x >= 0 && x < n && y >= 0 && y < m && visited[x][y] == false && adjMat[x][y] == 1);
}

void DFSUtil(vector<vector<int>> &adjMat, vector<vector<bool>> &visited, int x, int y)
{
  visited[x][y] = true;
  cnt++;
  for (int i = 0; i < 4; i++)
  {
    int x_ = dx[i] + x;
    int y_ = dy[i] + y;
    if (isSafe(adjMat, visited, x_, y_))
    {
      DFSUtil(adjMat, visited, x_, y_);
    }
  }
}
int findMaxAreaIsland(vector<vector<int>> &adjMat)
{
  int n = adjMat.size();
  int m = adjMat[0].size();
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  int ans = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (visited[i][j] == false && adjMat[i][j] == 1)
      {
        DFSUtil(adjMat, visited, i, j);
        ans = max(ans, cnt);
        cnt = 0;
      }
    }
  }
  return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adjMat(n, vector<int>(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> adjMat[i][j];
    }
  }
  cout << findMaxAreaIsland(adjMat);
  return 0;
}
