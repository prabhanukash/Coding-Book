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

    if (v == u)
      return 0;
    if (sz[u] < sz[v])
      swap(u, v);
    pr[v] = u;
    sz[u] += sz[v];
    return 1;
  }
};
struct query
{
  int idx;
  string type;
  int src;
  int dst;
};
bool comp(query &a, query &b)
{
  return a.idx > b.idx;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int n, m, k;
  cin >> n >> m >> k;
  UnionFind uf(n);
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
  }
  vector<query> queries(k);
  vector<string> ans(k, "");
  for (int i = 0; i < k; i++)
  {
    string t;
    cin >> t;
    int src, dst;
    cin >> src >> dst;
    queries[i].idx = i;
    queries[i].type = t;
    queries[i].src = src;
    queries[i].dst = dst;
  }
  sort(queries.begin(), queries.end(), comp);

  for (int i = 0; i < k; i++)
  {
    if (queries[i].type == "ask")
    {
      if (uf.find(queries[i].src, queries[i].dst))
      {
        ans[queries[i].idx] = "YES";
      }
      else
        ans[queries[i].idx] = "NO";
    }
    else
    {
      uf.un(queries[i].src, queries[i].dst);
    }
  }
  for (string s : ans)
  {
    if (s != "")
      cout << s << endl;
  }
}