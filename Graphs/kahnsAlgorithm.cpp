#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n,m;
    cin >> n>>m;
    adj.resize(n + 1);
    vector<int> indeg(n + 1, 0);
    for (int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;
        indeg[v]++;
        adj[u].push_back(v);
    }
    queue<int> q;
    for (int i = 1; i <= n;i++){
        if(indeg[i]==0)
            q.push(i);
    }
    vector<int> ans;
    while(q.size()>0){
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(int v:adj[u]){
            if(--indeg[v]==0)
                q.push(v);
        }
    }
    if(ans.size()==n){
        for(int val:ans)
            cout << val << ' ';
        cout << '\n';
    }
    else
        cout << "-1\n";
        return 0;
}