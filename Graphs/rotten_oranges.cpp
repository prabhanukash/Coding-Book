#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool isSafe(vector<vector<int>> &adjMat, int x, int y)
{
  int n = adjMat.size();
  int m = adjMat[0].size();
  return (x >= 0 && x < n && y >= 0 && y < m && adjMat[x][y] == 1);
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int n, m, total = 0;
  cin >> n >> m;
  vector<vector<int>> adjMat(n, vector<int>(m));
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> adjMat[i][j];
      if (adjMat[i][j] != 0)
        total++;
      if (adjMat[i][j] == 2)
      {
        q.push({i, j});
      }
    }
  }
  int cnt = 0, ans = 0;
  while (q.size() > 0)
  {
    int sz = q.size();
    cnt += sz;
    while (sz--)
    {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++)
      {
        int x_ = x + dx[i];
        int y_ = y + dy[i];
        if (isSafe(adjMat, x_, y_))
        {
          adjMat[x_][y_] = 2;
          q.push({x_, y_});
        }
      }
    }
    if (!q.empty())
      ans++;
  }
  if (total == cnt)
  {
    cout << ans << endl;
  }
  else
  {
    cout << -1 << endl;
  }
  return 0;
}
