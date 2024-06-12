#include <bits/stdc++.h>
using namespace std;
class union_find
{
  int *pr;
  int *sz;

public:
  union_find(int n)
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
    if (sz[v] > sz[u])
      swap(u, v);
    pr[v] = u;
    sz[u] += sz[v];
    return 1;
  }
};
int main()
{
// #ifndef ONLINE_JUDGE
//   freopen("inp.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);
// #endif
  int n;
  cin >> n;
  vector<int> nodes[26];
  for (int i = 1; i <= n; i++)
  {
    string s;
    cin >> s;
    for (char ch : s)
    {
      int val = ch - 'a';
      nodes[val].push_back(i);
    }
  }
  int comp = n;
  union_find dsu(n);

  for (int i = 0; i < 26; i++)
  {
    for (int j = 0; j + 1 < nodes[i].size(); j++)
    {
      comp -= dsu.un(nodes[i][j], nodes[i][j + 1]);
    }
  }
  cout << comp << endl;
  return 0;
}