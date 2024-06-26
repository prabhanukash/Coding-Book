#include <bits/stdc++.h>
using namespace std;
class UnionFind
{
  int *pr;
  int *sz;
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
    if (pr[i] == i)
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

  return 0;
}
