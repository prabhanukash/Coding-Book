#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> adj[N];
int dp[N], val[N], x;

void dfs(int v, int p)
{
  dp[v] = val[v];
  int sum = val[v];
  for (int nb : adj[v])
  {
    if (p == nb)
      continue;
    dfs(nb, v);
    sum += dp[nb];
  }
  dp[v] = max(sum, -x);
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
    cin >> n >> x;
    for (int i = 1; i <= n+1;i++){
      adj[i].clear();
      dp[i] = val[i] = 0;
    }
      for (int i = 1; i <= n; i++)
        cin >> val[i];
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
  return 0;
}
