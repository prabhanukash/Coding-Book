#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void DFSUtil(vector<vector<int>> &adjMat, int x, int y, int clr)
{
  adjMat[x][y] = -clr;
  int cnt = 0;
  for (int i = 0; i < 4; i++)
  {
    int x_ = dx[i] + x;
    int y_ = dy[i] + y;
    if (x_ < 0 || y_ < 0 || x_ >= adjMat.size() || y_ >= adjMat[0].size() || abs(adjMat[x_][y_]) != clr)
      continue;
    cnt++;
    if (adjMat[x_][y_] == clr)
      DFSUtil(adjMat, x_, y_, clr);
  }
  if (cnt == 4)
    adjMat[x][y] = clr;
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
  int src, dest, clr;
  cin >> src >> dest >> clr;
  DFSUtil(adjMat, src, dest, adjMat[src][dest]);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (adjMat[i][j] < 0)
      {
        adjMat[i][j] = clr;
      }
      cout << adjMat[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}
