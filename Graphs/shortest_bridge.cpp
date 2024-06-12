#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int, pair<int, int>>> q;

bool isSafe(vector<vector<int>> &adjMat, vector<vector<bool>> &visited, int x, int y)
{
  int n = adjMat.size();
  int m = adjMat[0].size();
  return (x >= 0 && x < n && y >= 0 && y < m && visited[x][y] == false);
}

void DFSUtil(vector<vector<int>> &adjMat, vector<vector<bool>> &visited, int x, int y)
{
  visited[x][y] = true;
  q.push({0, {x, y}});
  for (int i = 0; i < 4; i++)
  {
    int x_ = dx[i] + x;
    int y_ = dy[i] + y;
    if (isSafe(adjMat, visited, x_, y_) && adjMat[x_][y_] == 1)
    {
      DFSUtil(adjMat, visited, x_, y_);
    }
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
  vector<vector<int>> adjMat(n, vector<int>(m));
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> adjMat[i][j];
    }
  }
  int count = 0;
  for (int i = 0; i < n && count < 1; i++)
  {
    for (int j = 0; j < m && count < 1; j++)
    {
      if (adjMat[i][j] == 1 && visited[i][j] == false)
      {

        DFSUtil(adjMat, visited, i, j);
        count++;
      }
    }
  }
  int ans = INT_MAX;
  while (!q.empty())
  {
    pair<int, pair<int, int>> p = q.front();
    q.pop();
    int dist = p.first;
    int x = p.second.first;
    int y = p.second.second;
    for (int i = 0; i < 4; i++)
    {
      int x_ = dx[i] + x;
      int y_ = dy[i] + y;

      if (isSafe(adjMat, visited, x_, y_) && adjMat[x_][y_]==0)
      {
        visited[x_][y_] = true;
        q.push({dist + 1, {x_, y_}});
      } else if (isSafe(adjMat, visited, x_, y_) && adjMat[x_][y_]==1){
        ans = min(ans, dist);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
