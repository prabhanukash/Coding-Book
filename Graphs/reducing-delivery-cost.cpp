#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> adj;
int n, m, k;
vector<vector<int>> dist;
vector<vector<int>> routes;

void dijisktra(int i)
{
  dist[i][i] = 0;
  priority_queue<pair<int, int>> q;
  q.push({0, i});
  while (!q.empty())
  {
    int v = q.top().second;
    q.pop();
    for (auto it : adj[v])
    {
      int nb = it.first;
      int w = it.second;
      if (dist[i][v] + w < dist[i][nb])
      {
        dist[i][nb] = dist[i][v] + w;
        q.push({-dist[i][nb], nb});
      }
    }
  }
}
int get(int i, int j)
{
  int ans = 0;
  for (vector<int> &v : routes)
    ans += min({dist[v[0]][v[1]], dist[v[0]][i] + dist[j][v[1]], dist[v[1]][i] + dist[j][v[0]]});

  return ans;
}

int main()
{
  cin >> n >> m >> k;
  adj.resize(n + 1);
  vector<vector<int>> edges;
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u, v});
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  dist.assign(n + 1, vector<int>(n + 1, INT_MAX));
  for (int i = 1; i <= n; i++)
  {
    dijisktra(i);
  }
  routes.assign(k, vector<int>(2));
  for (vector<int> &v : routes)
    cin >> v[0] >> v[1];

  int ans = INT_MAX;
  for (vector<int> &v : edges)
		ans = min(ans, get(v[0], v[1]));
  cout << ans << endl;

  return 0;
}
