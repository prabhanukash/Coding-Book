#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> col;
bool dfs(int u, int c)
{
    vis[u] = true;
    col[u] = c;
    for (int v : adj[u])
    {
        if (vis[v] == false)
        {
            bool ch = dfs(v, c ^ 1);
            if (ch == false)
                return false;
        }
        else
        {
            if (col[u] == col[v])
                return false;
        }
    }
    return true;
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
    vis.resize(n + 1, false);
    col.resize(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            bool ans = dfs(i, 0);
            if (ans == false)
            {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";

    return 0;
}