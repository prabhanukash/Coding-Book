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
    int ans = 0;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        int val = arr[i];
        while (arr[i] != INT_MIN)
        {
            int tmp = val;
            val = arr[val];
            cnt++;
            arr[tmp] = INT_MIN;
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}