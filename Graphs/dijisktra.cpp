#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<pair<int, int>> adj[N];

int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  priority_queue<pair<int, int>> q;
  vector<int> dist(n + 1, INT_MAX);
  int src;
  cin >> src;
  q.push({0, src});
  dist[src] = 0;
  while (!q.empty())
  {
    pair<int, int> p = q.top();
    q.pop();
    int w = p.first;
    int v = p.second;
    for (auto it : adj[v])
    {
      int nb = it.first;
      int w = it.second;
      if (dist[v] + w < dist[nb])
      {
        dist[nb] = dist[v] + w;
        q.push({-dist[nb], nb});
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout << dist[i] << ' ';
  }
  return 0;
}