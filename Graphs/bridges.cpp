#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> pre, low;
int timer;
vector<pair<int, int>> bridges;

void dfs(int v, int p = -1)
{
  pre[v] = low[v] = ++timer;
  for (int nb : adj[v])
  {
    if (nb == p)
      continue;
    if (pre[nb])
    {
      low[v] = min(low[v], pre[nb]);
    }
    else
    {
      dfs(nb, v);
      low[v] = min(low[nb], low[v]);
      if (low[nb] > pre[v])
      {
        bridges.push_back({v, nb});
      }
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
  adj.resize(n);
  pre.assign(n, 0);
  low.assign(n, 0);
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, -1);
  for (auto p : bridges)
  {
    cout << p.first << ' ' << p.second << '\n';
  }
}