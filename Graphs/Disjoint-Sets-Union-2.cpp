#include <bits/stdc++.h>
using namespace std;
class UnionFind
{
  int *pr;
  int *sz;
  int *mn;
  int *mx;

public:
  UnionFind(int n)
  {
    pr = new int[n + 1];
    sz = new int[n + 1];
    mn = new int[n + 1];
    mx = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
      pr[i] = i;
      sz[i] = 1;
      mn[i] = i;
      mx[i] = i;
    }
  }
  int root(int i)
  {
    if (i == pr[i])
      return i;
    return pr[i] = root(pr[pr[i]]);
  }
  tuple<int, int, int> get(int u)
  {
    int r = root(u);
    return {mn[r], mx[r], sz[r]};
  }
  int un(int i, int j)
  {
    int u = root(i);
    int v = root(j);
    if (u == v)
      return 0;

    if (sz[u] < sz[v])
      swap(u, v);
    pr[v] = u;
    sz[u] += sz[v];
    mn[u] = min(mn[u], mn[v]);
    mx[u] = max(mx[u], mx[v]);
    return 1;
  }
};
int main()
{
// #ifndef ONLINE_JUDGE
//   freopen("inp.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);
// #endif
  int n, q;
  cin >> n >> q;
  UnionFind uf(n);
  while (q--)
  {
    string s;
    cin >> s;
    int u, v;
    if (s == "get")
    {
      cin >> u;
      int min_elem, max_elem, set_size;
      tie(min_elem, max_elem, set_size) = uf.get(u);
      cout << min_elem << " " << max_elem << " " << set_size << endl;
    }
    else
    {
      cin >> u >> v;
      uf.un(u, v);
    }
  }
}