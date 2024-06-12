#include <bits/stdc++.h>
using namespace std;

void DFSUtil(vector<vector<int>> &adjMat, int x, int y, int oldcolor, int newcolor)
{
  if (x >= adjMat.size() || y >= adjMat[0].size() || x < 0 || y < 0)
    return;
  if (adjMat[x][y] != oldcolor)
    return;
  adjMat[x][y] = newcolor;
  DFSUtil(adjMat, x + 1, y, oldcolor, newcolor);
  DFSUtil(adjMat, x - 1, y, oldcolor, newcolor);
  DFSUtil(adjMat, x, y + 1, oldcolor, newcolor);
  DFSUtil(adjMat, x, y - 1, oldcolor, newcolor);
}
void floodFill(vector<vector<int>> &adjMat, int src, int dest, int clr)
{
  int n = adjMat.size();
  int m = adjMat[0].size();

  int orgClr = adjMat[src][dest];
  if (orgClr == clr)
    return;

  DFSUtil(adjMat, src, dest, orgClr, clr);
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
  floodFill(adjMat, src, dest, clr);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << adjMat[i][j] << ' ';
    }
    cout << '\n';
  }
    return 0;
}
