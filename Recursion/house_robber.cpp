#include <bits/stdc++.h>
using namespace std;
int f(vector<int> &nums, int idx, vector<int> &dp)
{
    if (idx >= nums.size())
    {
        return 0;
    }
    if (dp[idx] != -1)
        return dp[idx];
    int sp1 = nums[idx] + f(nums, idx + 2, dp);
    int sp2 = f(nums, idx + 1, dp);
    return dp[idx] = max(sp1, sp2);
}
int main()
{
    vector<int> arr(4);
    arr = {1, 2, 3, 4};
    vector<int> dp(arr.size(), -1);
    cout << f(arr, 0, dp);
}