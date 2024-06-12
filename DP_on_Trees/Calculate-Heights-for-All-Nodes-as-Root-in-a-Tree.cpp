#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> adj[N];
int in[N], out[N];
void dfs1(int v, int p)
{
  in[v] = 0;
  for (int nb : adj[v])
  {
    if (p == nb)
      continue;
    dfs1(nb, v);
    in[v] = max(in[nb] + 1, in[v]);
  }
}
void dfs2(int v, int p)
{
  int mx1 = -1;
  int mx2 = -1;
  for (int nb : adj[v])
  {
    if (nb == p)
      continue;
    if (in[nb] >= mx1)
      mx2 = mx1, mx1 = in[nb];
    else if (in[nb] > mx2)
      mx2 = in[nb];
  }
  for (int nb : adj[v])
  {
    if (nb == p)
      continue;
    int use = mx1;
    if (mx1 == in[nb])
      use = mx2;
    out[nb] = max(use + 2, 1 + out[v]);
    dfs2(nb, v);
  }
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  for (int i = 1; i < n; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs1(1, 0); 
  dfs2(1, 0); 

  for (int i = 1; i <= n;i++){
    cout << max(in[i], out[i]) << ' ';
  }
    return 0;
}
