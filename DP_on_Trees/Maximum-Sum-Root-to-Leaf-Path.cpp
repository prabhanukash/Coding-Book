#include <bits/stdc++.h>
using namespace std;
const int N = (1 * 1e6 + 5);
vector<int> adj[N];
int dp[N], values[N];
void dfs(int v, int p = -1)
{
  dp[v] = values[v];
  int mx = 0;
  for (int nb : adj[v])
  {
    if (nb == p)
      continue;
    dfs(nb, v);
    mx = max(mx, dp[nb]);
  }
  dp[v] += mx;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> values[i];
  }
  for (int i = 1; i < n; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0);
  cout << dp[1] << ' ';
  return 0;
}