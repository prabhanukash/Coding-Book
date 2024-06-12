#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> adj[N];
vector<pair<int,int>> paths
void dfs(int v,int p){
  if(v==n{
    
  })
  for(int nb:adj[v]){
    if(nb==p)continue;
    dfs
  }
}
int main()
{
  int n, m;
  cin >> m >> n;
  map<pair<int, int>, int> directedEdges;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    directedEdges[{u, v}] = 1;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  return 0;
}