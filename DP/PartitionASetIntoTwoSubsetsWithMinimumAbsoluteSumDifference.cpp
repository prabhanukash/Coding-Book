#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> arr(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
        cin >> arr[i], sum += arr[i];
    dp.resize(n + 1, vector<int>(sum + 1, -1));

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 0; i <= n; i++)
        dp[0][i] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j];

            if (arr[i - 1] <= j)
                dp[i][j] |= dp[i - 1][j - arr[i - 1]];
        }
    }
    int ans = INT_MAX;
    for (int i = sum / 2; i >= 0; i--)
    {
        if (dp[n][i] == true)
        {
            ans = sum - 2 * i;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}