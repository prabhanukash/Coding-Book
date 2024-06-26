#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> adj[N];
bool visited[N];
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
    adj[v].push_back(u);
  }
  queue<int> q;
  q.push(1);
  visited[1] = true;
  while (!q.empty())
  {
    int v = q.front();
    q.pop();
    cout << v << ' ';
    for (int nb : adj[v])
    {
      if (visited[nb] == false)
      {
        visited[nb] = true;
        q.push(nb);
      }
    }
  }
  return 0;
}
