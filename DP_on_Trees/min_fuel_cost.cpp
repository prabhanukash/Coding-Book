#include <bits/stdc++.h>
using namespace std;
vector<int> sub;
void dfs(vector<vector<int>> &adj, int v, int p = -1)
{
  sub[v] = 1;
  for (auto nb : adj[v])
  {
    if (nb == p)
      continue;
    dfs(adj, nb, v);
  }
  if (p != -1)
    sub[p] += sub[v];
}
int minimumFuelCost(vector<vector<int>> &roads, int seats)
{
  int n = roads.size() + 1;
  sub.resize(n + 1, 0);
  vector<vector<int>> adj(n + 1);

  for (auto it : roads)
  {
    int u = it[0];
    int v = it[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(adj, 0, -1);
  int ans = 0;
  for (int i = 1; i < n; ++i)
  {
    int cnt = sub[i];
    ans += ((cnt + seats - 1) / seats);
  }
  return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int n, seats;
  cin >> n >> seats;
  vector<vector<int>> roads = {};
  cout << minimumFuelCost(roads, 1);
  return 0;
}