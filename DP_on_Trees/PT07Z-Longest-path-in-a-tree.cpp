#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
int maxDist, maxNode;
void dfs(int v, int p, int d)
{
  if (d > maxDist)
    maxDist = d, maxNode = v;
  for (int nb : adj[v])
  {
    if (nb == p)
      continue;
    dfs(nb, v, d + 1);
  }
}
int main()
{
// #ifndef ONLINE_JUDGE
//   freopen("inp.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);
// #endif
  int n;
  cin >> n;
  adj.resize(n + 1);
  for (int i = 1; i < n; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  maxDist = -1;
  dfs(1, 0, 0);
  maxDist = -1;
  dfs(maxNode, 0, 0);
  cout << maxDist << endl;
  return 0;
}