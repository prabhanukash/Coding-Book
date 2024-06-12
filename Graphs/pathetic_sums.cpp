#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
void dfs(vector<vector<int>> &adj, vector<int> &col, int v, int p, int c)
{
  col[v] = c;
  for (int nb : adj[v])
  {
    if (nb == p)
      continue;
    dfs(adj, col, nb, v, c ^ 1);
  }
}
int main()
{
// #ifndef ONLINE_JUDGE
//   freopen("inp.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);
// #endif
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> col(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dfs(adj, col, 1, -1, 0);
    for (int i = 1; i <= n; i++)
    {
      if (col[i] == 0)
        col[i] = 2;
      cout << col[i] << ' ';
    }
    cout << endl;
  }
  return 0;
}