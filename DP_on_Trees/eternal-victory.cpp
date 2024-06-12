#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<pair<int, long long>> adj[N];
long long dp[N];
void dfs(int v, int p)
{
  dp[v] = 0;
  for (auto nb : adj[v])
  {
    int u = nb.first;
    int w = nb.second;
    if (u == p)
      continue;
    dfs(u, v);
    dp[v] = max(dp[v], w + dp[u]);
  }
}
int main()
{
  int n;
  cin >> n;
  long long sum_of_edges = 0;
  for (int i = 1; i < n; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
    sum_of_edges += w;
  }
  dfs(1, 0);
  if (sum_of_edges == dp[1])
  {
    cout << sum_of_edges << endl;
  }
  else
  {
    cout << 2 * sum_of_edges - dp[1] << endl;
  }
  return 0;
}