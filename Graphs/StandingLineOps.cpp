#include <bits/stdc++.h>
using namespace std;
class union_find
{
  int *pr;
  int *sz;

public:
  union_find(int n)
  {
    pr = new int[n + 2];
    sz = new int[n + 2];
    for (int i = 1; i <= n; i++)
    {
      pr[i] = i;
      sz[i] = 1;
    }
  }
  int root(int i)
  {
    if (pr[i] == i)
      return i;
    return pr[i] = root(pr[pr[i]]);
  }
  int find(int i, int j)
  {
    return (root(i) == root(i));
  }
  int un(int i, int j)
  {
    int u = root(i);
    int v = root(j);

    if (u == v)
      return 0;

    if (sz[v] > sz[u])
      swap(u, v);
    pr[v] = u;
    sz[u] += sz[v];
    return 1;
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
  union_find dsu(n);
  int m;
  cin >> m;
  while (m--)
  {
    char ch;
    int x;
    cin >> ch >> x;
    if (ch == '-')
    {
      dsu.un(x + 1, x);
    }
    else
    {
      int res = dsu.root(x);
      if (res == n + 2)
      {
        cout << -1 << endl;
      }
      else
      {
        cout << res << endl;
      }
    }
  }
  return 0;
}