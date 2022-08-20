#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> arr;
vector<vector<bool>> vis;
queue<pair<int, int>> q;
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void dfs(int x, int y)
{
    q.push({x, y});
    vis[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (X < 0 or Y < 0 or X >= n or Y >= m or vis[X][Y] == true or arr[X][Y] == 0)
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
    vis.resize(n, vector<bool>(m, false));
    int flg = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n and !flg; i++)
    {
        for (int j = 0; j < m and !flg; j++)
        {
            if (arr[i][j] == 1)
            {
                dfs(i, j);
                flg = 1;
            }
        }
    }
    int ans = 0;
    while (q.size() > 0)
    {
        int sz = q.size();
        while (sz--)
        {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            for (int i = 0; i < 4; i++)
            {
                int X = x + dx[i];
                int Y = y + dy[i];
                if (X < 0 or Y < 0 or X >= n or Y >= m or vis[X][Y] == true)
                    continue;
                if (arr[X][Y] == 1)
                {
                    cout << ans << '\n';
                    return 0;
                }
                q.push({X, Y});
            }
        }
        ans++;
    }
    cout << "-1\n";
    return 0;
}