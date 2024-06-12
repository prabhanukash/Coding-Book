#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
vector<long long> adj[N];
long long  in[N], out[N], val[N];
void dfs1(long long v, long long p)
{
  for (long long nb : adj[v])
  {
    if (p == nb)
      continue;
    dfs1(nb, v);
    in[v] = max(in[nb] + max(0LL, val[nb] - val[v]), in[v]);
  }
}
void dfs2(long long v, long long p)
{
  long long mx1 = -1;
  long long mx2 = -1;
  for (long long nb : adj[v])
  {
    if (nb == p)
      continue;
    if (in[nb] + max(0LL, val[nb] - val[v]) > mx1)
      mx2 = mx1, mx1 = in[nb] + max(0LL, val[nb] - val[v]);
    else if (in[nb] + max(0LL, val[nb] - val[v]) > mx2)
      mx2 = in[nb] + max(0LL, val[nb] - val[v]);
  }
  for (long long nb : adj[v])
  {
    if (nb == p)
      continue;
    long long use = mx1;
    if (mx1 == in[nb]+ max(0LL, val[nb] - val[v]))
      use = mx2;
    out[nb] = max(use + max(0LL, val[v] - val[nb]), out[v] + max(0LL, val[v] - val[nb]));
    dfs2(nb, v);
  }
}
int main()
{
// #ifndef ONLINE_JUDGE
//   freopen("inp.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);
// #endif
  long long n, q;
  cin >> n >> q;
  for (long long i = 0; i < n; i++)
    cin >> val[i];
  for (long long i = 1; i < n; i++)
  {
    long long u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs1(0, -1);
  dfs2(0, -1);
  while (q--)
  {
    long long x;
    cin >> x;
    cout << max(in[x], out[x]) << endl;
  }
  return 0;
}
