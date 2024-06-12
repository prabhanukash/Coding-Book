#include <bits/stdc++.h>
using namespace std;
class UnionFind
{
  int *pr;
  int *sz;

public:
  UnionFind(int n)
  {
    pr = new int[n + 1];
    sz = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
      pr[i] = i;
      sz[i] = 1;
    }
  }
  int root(int i)
  {
    if (i == pr[i])
      return i;
    return pr[i] = root(pr[pr[i]]);
  }
  int find(int i, int j)
  {
    return (root(i) == root(j));
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
    return 1;
  }
};
int main()
{
// #ifndef ONLINE_JUDGE
//       freopen("inp.txt", "r", stdin);
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
    cin >> u >> v;
    if (s == "get")
    {

      if (uf.find(u, v))
      {
        cout << "YES\n";
      }
      else
        cout << "NO\n";
    }
    else
    {
      uf.un(u, v);
    }
  }
}