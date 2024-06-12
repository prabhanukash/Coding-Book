#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int mod = 1000000007;
vector<int> adj[N];
int visited[N];
int dfs(int v)
{
  int cnt = 1;
  visited[v] = 1;
  for (int nb : adj[v])
  {
    if (visited[nb])
      continue;
    cnt += dfs(nb);
  }
  return cnt;
}
int pwmd(int a, int n = mod - 2)
{
  if (!n)
    return 1;
  int pt = pwmd(a, n / 2);
  pt *= pt, pt %= mod;
  if (n & 1)
    pt *= a, pt %= mod;
  return pt;
}
int main()
{
  #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  #endif
  int n, k;
  cin >> n >> k;
  for (int i = 1; i < n; i++)
  {
    int u, v, col;
    cin >> u >> v >> col;
    if (col == 1)
      continue;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int ans = pwmd(n, k);
  for (int i = 1; i <= n; i++)
  {
    if (visited[i])
      continue;
    int cnt = dfs(i);
    ans -= pwmd(cnt, k);
    ans = (ans + mod) % mod;
  }
  cout << ans << endl;
  return 0;
}