#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> adj[N];
int indeg[N];

int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    indeg[v]++;
  }
  queue<int> q; 
  for (int i = 0; i <n; i++)
  {
    if (indeg[i] == 0)
    {
      q.push(i);
    }
  }
  while (!q.empty())
  {
    int v = q.front();
    q.pop();
    cout << v << ' ';
    for (int nb : adj[v])
    {
      indeg[nb]--;
      if (indeg[nb] == 0)
      {
        q.push(nb);
      }
    }
  }
  return 0;
}
