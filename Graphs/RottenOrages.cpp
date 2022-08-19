#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> mat;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n,m;
    cin >> n >> m;
    mat.resize(n, vector<int>(m));
    queue<pair<int, int>> q;
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int val;
            cin >> val;
            mat[i][j] = val;
            if (val != 0)
                tot++;
            if (val == 2)
                q.push({i, j});
        }
    }
    int ans = 0,cnt=0;
    while (q.size()>0)
    {
        int sz = q.size();
        cnt += sz;
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
                if (X < 0 or Y < 0 or X >= n or Y >= m or mat[X][Y] != 1)
                    continue;
                mat[X][Y] = 2;
                q.push({X, Y});
            }
        }
        if(q.empty()==false)
            ans++;
    }
    if (tot==cnt)
        cout << ans << '\n';
    else
        cout << "-1\n";
    return 0;
}