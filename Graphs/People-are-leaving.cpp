#include <bits/stdc++.h>
using namespace std;
class UnionFind
{
  int *pr;
  int *sz;

public:
  UnionFind(int n)
  {
    pr = new int[n + 2];
    sz = new int[n + 2];
    for (int i = 1; i <= n + 1; i++)
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
    pr[v] = u;
    return 1;
  }
};
int main()
{
  // #ifndef ONLINE_JUDGE
  //   freopen("inp.txt", "r", stdin);
  //   freopen("out.txt", "w", stdout);
  // #endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  UnionFind dsu(n);
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
      int ans = dsu.root(x);
      if (ans == n + 1)
      {
        cout << "-1\n";
      }
      else
        cout << ans << endl;
    }
  }
}