#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> arr;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m;
map<string, int> ans;

string str;
void dfs(int x, int y)
{
    arr[x][y] = 0;
    if(x-1>=0 and arr[x-1][y]==1){
        str += 'U';
        dfs(x - 1, y);
    }
    if(x+1<n and arr[x+1][y]==1){
        str += 'D';
        dfs(x + 1, y);
    }
    if(y-1>=0 and arr[x][y-1]==1){
        str += 'L';
        dfs(x,y-1);
    }
    if(y+1<m and arr[x][y+1]==1){
        str += 'R';
        dfs(x, y+1);
    }
    str += 'Z';
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> m;
    arr.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n;i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j]==1){
                str = 'X';
                dfs(i, j);
                ans[str]++;
            }
        }
    }
    cout << ans.size();
    return 0;
}