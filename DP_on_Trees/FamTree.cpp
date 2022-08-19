#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
int maxDiff;
vector<int> a;
vector<vector<int>> dp;
pair<int, int> dfs(int u, int p)
{
    int min_val = a[u], max_val = a[u];

    for (int v : adj[u])
    {
        if (v == p)
            continue;

        pair<int, int> ch = dfs(v, u);
        min_val = min(ch.first, min_val);
        max_val = max(ch.second, max_val);
    }
    maxDiff = max({maxDiff, max_val - a[u], a[u] - min_val});
    return {min_val, max_val};
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    adj.resize(n + 1);
    dp.resize(n + 1, vector<int>(2));
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int root = 0;
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> p;
        if (p == -1)
        {
            root = i;
            continue;
        }
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    dfs(root, 0);
    cout << maxDiff << '\n';
    return 0;
}