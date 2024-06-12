#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool isSafe(vector<vector<int>> &adjMat, vector<vector<bool>> &visited, int x, int y)
{
  int n = adjMat.size();
  int m = adjMat[0].size();
  return (x >= 0 && x < n && y >= 0 && y < m && visited[x][y] == false && adjMat[x][y] == 0);
}

void DFSUtil(vector<vector<int>> &adjMat, vector<vector<bool>> &visited, int x, int y)
{
  visited[x][y] = true;
  adjMat[x][y] = 1;
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
void convertBorderLandsToWater(vector<vector<int>> &adjMat)
{
  int n = adjMat.size();
  int m = adjMat[0].size();
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
      {
        if (visited[i][j] == false && adjMat[i][j] == 0)
        {
          DFSUtil(adjMat, visited, i, j);
        }
      }
    }
  }
}

int findNoOfClosedIslands(vector<vector<int>> &adjMat)
{
  int noOfClosedIslands = 0;
  int n = adjMat.size();
  int m = adjMat[0].size();
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (visited[i][j] == false && adjMat[i][j] == 0)
      {
        DFSUtil(adjMat, visited, i, j);
        noOfClosedIslands++;
      }
    }
  }

  return noOfClosedIslands;
}
int noOfClosedIslands(vector<vector<int>> &adjMat)
{
  convertBorderLandsToWater(adjMat);
  return findNoOfClosedIslands(adjMat);
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
  cout << noOfClosedIslands(adjMat) << endl;

  return 0;
}
