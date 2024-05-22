#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> dp;
void dfs(int u, int p){
    dp[u] = 1;
    for(int v:adj[u]){
        if(v==p)continue;
        dfs(v, u);
        dp[u] += dp[v];
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    dp.resize(n + 1, 0);
    adj.resize(n + 1);
    for (int i = 0; i < n - 1;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n;i++) {
        cout << i << ' ' << dp[i] << '\n';
    }
        return 0;
}