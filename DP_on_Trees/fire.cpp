#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
vector<int> adj[N];
int dp[N]; // dp[i] represents min time to spread fire among each node in its subtree
void dfs(int v, int p)
{
  vector<int> child_values;

  for (int nb : adj[v])
  {
    if (nb == p)
      continue;
    dfs(nb, v);
    child_values.push_back(dp[nb]);
  }
  sort(child_values.rbegin(), child_values.rend());

  int secs = 1;
  dp[v] = 0;

  for (int val : child_values)
  {
    dp[v] = max(val + secs, dp[v]);
    secs++;
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
  dfs(1, 0);
  cout << dp[1] << endl;
}