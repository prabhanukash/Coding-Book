#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 0)
                q.push({i, j});
            else
                arr[i][j] = -1;
        }
    }
    while (q.size() > 0)
    {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        for (int i = 0; i < 4; i++)
        {
            int X = x + dx[i];
            int Y = y + dy[i];
            if (X >= 0 and X < n and Y >= 0 and Y < m and arr[X][Y] < 0)
            {
                arr[X][Y] = arr[x][y] + 1;
                q.push({X, Y});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}