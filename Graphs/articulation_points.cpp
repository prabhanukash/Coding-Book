#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> pre, low, art;
int timer;
int forwardEdges;

void dfs(int v, int p = -1)
{
  pre[v] = low[v] = ++timer;
  for (int nb : adj[v])
  {
    if (nb == p)
      continue;
    if (pre[nb] == -1)
    {
      forwardEdges++;
      dfs(nb, v);
      low[v] = min(low[v], low[nb]);
      if (pre[v] <= low[nb] && p!=-1)
      {
        art.push_back(v);
      }
    }
    else
    {
      low[v] = min(low[v], pre[nb]);
    }
  }
  if(p==-1 && forwardEdges>1)
    art.push_back(v);
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

  pre.assign(n, -1);
  low.assign(n, -1);
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, -1);
  for (auto p : art)
  {
    cout << p << ' ';
  }
}