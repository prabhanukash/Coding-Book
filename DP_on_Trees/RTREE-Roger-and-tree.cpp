// SPOJ 20775: Roger and tree
// http://www.spoj.com/problems/RTREE/
//
// Solution: dynamic programming (rooted-tree longest path)
//
// maintain
//   1) longest path under u
//   2) longest half path (i.e., from u to some leaf)
// then the DP formula is obtained.

#include <bits/stdc++.h>
using namespace std;


struct edge
{
  int src, dst;
};
struct tree
{
  int n;
  vector<vector<edge>> adj;
  vector<int> half, full;
  tree(int n) : n(n), adj(n), half(n), full(n) {}

  void add_edge(int src, int dst)
  {
    adj[src].push_back({src, dst});
    adj[dst].push_back({dst, src});
  }

  void compute(int v, int p = -1)
  {
    bool no_child = true;
    for (auto e : adj[v])
    {
      if (e.dst == p)
        continue;
      no_child = false;
      compute(e.dst, e.src);
    }
    if (no_child)
    {
      half[v] = full[v] = 0;
    }
    else
    {
      for (edge e : adj[v])
      {
        int nb = e.dst;
        if (nb == p)
          continue;
        half[v] = max(half[v], 1 + half[nb]);
        full[v] = max(full[v], full[nb]);
      }
      full[v] = max(full[v], half[v]);

      int max1 = -1, max2 = -1;
      for (int i = 0; i < adj[v].size(); ++i)
      {
        int nb = adj[v][i].dst;
        if (nb == p)
          continue;
        if (half[nb] > max1)
        {
          max2 = max1;
          max1 = half[nb];
        }
        else if (half[nb] > max2)
        {
          max2 = half[nb];
        }
      }
      if (max1 >= 0 && max2 >= 0)
        full[v] = max(full[v], 2 + max1 + max2);
    }
  }
};

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  #endif
  int n;
  cin >> n;
  tree T(n);
  for (int i = 0; i < n - 1; ++i)
  {
    int u, v;
    cin >> u >> v;
    T.add_edge(u - 1, v - 1);
  }
  int r;
  cin >> r;
  T.compute(r - 1);

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i)
  {
    int u;
    cin >> u;
    cout << T.full[u - 1] << endl;
  }
}