#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    Solution() : ans(0), used(10, false){}

    int countNumbersWithUniqueDigits(int n)
    {
        // f(0, n);
        // return ans + 1;
        if (n > 10)
            return 0;
        vector<int> dp(11, 0);

        dp[0] = 1;
        dp[1] = 9;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] * (9 - i + 2);
        }

        int res = 0;
        for (int i = 0; i <= n; i++)
        {
            res += dp[i];
        }
        return res;
    }

private:
    vector<bool> used;
    int ans;
    vector<int> dp;
    void f(int idx, int n)
    {
        if (idx == n)
        {
            return;
        }
        unordered_set<int> st;
        for (int j = (idx == 0) ? 1 : 0; j < 10; j++)
        {
            if (used[j])
                continue;
            used[j] = true;
            ans++;
            f(idx + 1, n);
            used[j] = false;
        }
    }
};
int main()
{
    Solution solution;
    int n;
    cin >> n;
    cout << solution.countNumbersWithUniqueDigits(n);
    return 0;
}