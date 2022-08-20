#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> adj;
vector<bool> vis;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, 0});
        adj[v].push_back({u, 1});
    }
    vector<int> dist(n + 1, INT_MAX);
    deque<int> q; 
    dist[1] = 0;
    q.push_front(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop_front();
        if(u==n){
            cout << dist[u] << '\n';
            return 0;
        }
        for (auto it : adj[u])
        {
            if (dist[it.first] > dist[u] + it.second)
                dist[it.first] = dist[u] + it.second;
            if (it.second == 0)
                q.push_front(it.first);
            else
                q.push_back(it.first);
        }
    }
    cout << "-1\n";
    return 0;
}