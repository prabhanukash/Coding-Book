#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> vis;
void dfs(int u)
{
    vis[u] = true;
    for (int v : adj[u])
    {
        if (vis[v])
            continue;
        dfs(v);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1);
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            int val;
            cin >> val;
            if (val == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        cnt++;
        dfs(i);
    }
    cout << cnt << '\n';

    return 0;
}