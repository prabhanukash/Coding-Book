#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> adj[N];
int val[N], ans;

pair<int, int> dfs(int v, int p)
{
  int mn = val[v];
  int mx = val[v];
  for (int nb : adj[v])
  {
    if (p == nb)
      continue;
    pair<int, int> j = dfs(nb, v);
    mx = max(mx, j.second);
    mn = min(mn, j.first);
  }
  ans = max({ans, mx - val[v], val[v] - mn});
  return {mx, mn};
}
int main()
{
  int n;
  cin >> n;
  int p[n + 1];
  int root;
  for (int i = 1; i <= n; i++)
  {
    cin >> val[i];
  }
  for (int i = 1; i <= n; i++)
  {
    int val;
    cin >> val;
    if (val == -1)
    {
      root = i;
    }
    else
    {
      adj[i].push_back(val);
      adj[val].push_back(i);
    }
  }

  dfs(root, -1);
  cout << ans << endl;
}