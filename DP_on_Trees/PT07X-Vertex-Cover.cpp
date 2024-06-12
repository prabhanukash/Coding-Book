#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> adj[N];
int dp[N][2];

void dfs(int v, int p)
{
  dp[v][0] = 0;
  dp[v][1] = 1;
  for (int nb : adj[v])
  {
    if (nb == p)
      continue;
    dfs(nb, v);
    dp[v][0] += dp[nb][1];
    dp[v][1] += min(dp[nb][0],dp[nb][1]);
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

  for (int i = 1; i < n; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  cout << min(dp[1][0], dp[1][1]) << endl;
}