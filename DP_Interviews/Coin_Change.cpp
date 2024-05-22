#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> dp(m + 1, 1e9);
    dp[0] = 0;
    for (int amt = 1; amt <= m; amt++)
    {
        for (int val : arr)
        {
            if (val <= amt)
            {
                dp[amt] = min(dp[amt], dp[amt - val] + 1);
            }
        }
    }
    if (dp[m] != 1e9)
        cout << dp[m] << '\n';
    else
        cout << -1 << '\n';
    return 0;
}