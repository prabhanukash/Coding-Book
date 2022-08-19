#include <bits/stdc++.h>
using namespace std;
int n, m, row, col, color;
vector<vector<int>> arr;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void dfs(int x, int y, int c)
{
    arr[x][y] = -c;
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (X < 0 or Y < 0 or X >= n or Y >= m or abs(arr[X][Y]) != c)
            continue;
        cnt++;
        if (arr[X][Y] == c)
            dfs(X, Y, c);
    }
    if(cnt==4)
        arr[x][y] = c;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
     cin >> n >> m >> row >> col >> color;
    arr.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    dfs(row, col, arr[row][col]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] < 0)
            {
                arr[i][j] = color;
            }
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}