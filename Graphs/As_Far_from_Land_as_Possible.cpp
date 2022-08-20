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
    int arr[n][m];
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
                q.push({i, j});
        }
    }
    int ans = -1;
    while (q.size() > 0)
    {
        int sz = q.size();
        ans++;
        while (sz--)
        {

            pair<int, int> p = q.front();
            q.pop();
            int x= p.first;
            int y= p.second;
            for (int i = 0; i < 4; i++)
            {
                int X = x + dx[i];
                int Y = y + dy[i];
                if (X < 0 or Y < 0 or X >= n or Y >= m or arr[X][Y] == 1)
                    continue;
                q.push({X, Y});
                arr[X][Y] = 1;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}