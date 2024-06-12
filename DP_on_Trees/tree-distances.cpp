#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> adj[N];
int sub[N], in[N], out[N];
int n;
void dfs(int v, int p)
{
  sub[v] = 1;
  for (int nb : adj[v])
  {
    if (nb == p)
      continue;
    dfs(nb, v);
    sub[v] += sub[nb];
  }
}

void dfs1(int v, int p)
{
  in[v] = 0;
  for (int nb : adj[v])
  {
    if (nb == p)
      continue;
    dfs1(nb, v);
    in[v] += sub[nb] + in[nb];
  }
}
void dfs2(int v, int p)
{
  for (int nb : adj[v])
  {
    if (nb == p)
      continue;
    out[nb] = in[v] - (in[nb] + sub[nb]) + out[v] + (n - sub[nb]);
    dfs2(nb, v);
  }
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n;
  for (int i = 1; i < n; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  dfs1(1, 0);
  out[1] = 0;
  dfs2(1, 0);
  for (int i = 1; i <= n; i++)
    cout << in[i] + out[i] << ' ';
}
