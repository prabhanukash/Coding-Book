#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> vis;
int mod = 1e9 + 7;
int dfs(int u){
    int cnt = 1;
    vis[u] = true;
    for(int v:adj[u]){
        if(vis[v])
            continue;
        cnt += dfs(v);
    }
    return cnt;
}
int powmd(int a, int n = mod - 2)
{
    if (!n)
        return 1;
    int pt = powmd(a, n / 2);
    pt *= pt, pt %= mod;
    if (n & 1)
        pt *= a, pt %= mod;
    return pt;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n,k;
    cin >> n >> k;
    adj.resize(n + 1);
    vis.resize(n + 1,false);
    for (int i = 0; i < n - 1;i++){
        int u, v, col;
        cin >> u >> v >> col;
        if(col==1)continue;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = powmd(n, k);
    for (int i = 1; i <= n;i++){
        if(vis[i])continue;
        int num = dfs(i);
        ans -= powmd(num, k);
        ans = (ans + mod) % mod;
    }
    cout << ans << '\n';
    return 0;
}