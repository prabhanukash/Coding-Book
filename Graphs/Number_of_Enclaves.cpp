#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> arr;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void dfs(int x, int y)
{
    arr[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (X < 0 || Y < 0 || X >= n || Y >= m or arr[X][Y] == 0)
            continue;
        dfs(X, Y);
    }
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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 or j == 0 or i == n - 1 or j == m - 1)
            {
                if (arr[i][j] == 1)
                {
                    dfs(i, j);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j]==1)
                ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}