#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> vis;
vector<vector<int>> swaps = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {0, 2}};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    string inp = "";
    string tar = "123450";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            string x;
            cin >> x;
            inp += x;
        }
    }
    queue<string> q;
    q.push(inp);
    int ans = 0;
    while (q.size() > 0)
    {
        int sz = q.size();
        while (sz--)
        {
            string str = q.front();
            q.pop();
            if (str == tar)
            {
                cout << ans << '\n';
                return 0;
            }
            int idx = str.find("0");

            for (int val : swaps[idx])
            {
                string tmp = str;
                swap(tmp[idx], tmp[val]);
                if (vis.count(tmp))
                    continue;
                q.push(tmp);
                vis[tmp] = 1;
            }
        }
        ans++;
    }
    cout << "-1\n";
    return 0;
}