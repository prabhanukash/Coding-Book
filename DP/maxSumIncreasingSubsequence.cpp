#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int dp[n];
    dp[0] = arr[0];
    int ans = dp[0];
    for (int i = 1; i < n; i++)
    {
        int mx = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                mx = max(mx, dp[j]);
            }
        }
        dp[i] = arr[i] + mx;
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
    return 0;
}