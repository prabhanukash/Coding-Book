#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
vector<int> adj[N];
int val[N];

struct trio
{
  int inv, zeroes, ones;
};

bool comp(trio &a, trio &b)
{
  return a.ones * b.zeroes < b.ones * a.zeroes;
}
trio dfs(int v, int p)
{
  trio cur;
  cur.inv = 0, cur.zeroes = 0, cur.ones = 0;
  vector<trio> subtr;
  for (int nb : adj[v])
  {
    if (nb == p)
      continue;
    subtr.push_back(dfs(nb, v));
  }
  if (val[v] == 1)
    cur.ones++;
  else
    cur.zeroes++;

  for (trio &t : subtr)
  {
    cur.inv += t.inv;
    cur.inv += cur.ones * t.zeroes;

    cur.zeroes += t.zeroes;
    cur.ones += t.ones;
  }

  return cur;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> val[i];
    for (int i = 1; i < n; i++)
    {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    trio ans = dfs(1, 0);
    cout << ans.inv << endl;
  }

  return 0;
}