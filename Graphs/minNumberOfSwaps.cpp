#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n;i++){
        int val;
        cin >> val;
        arr[i] = {val, i};
    } 
    sort(arr.begin(), arr.end());
    int ans = 0;
    vector<bool> vis(n, false);
    for (int i = 0; i < n;i++){
        if(vis[i]==true or arr[i].second==i)
            continue;
        int clen = 0;
        int j = i;
        while(vis[j]==false){
            vis[j] = true;
            clen++;
            j = arr[j].second;
        }
        ans += (clen - 1);
    }
    cout << ans << '\n';
    return 0;
}