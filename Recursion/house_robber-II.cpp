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
    vector<int> arr(3);
    arr = {1, 2, 3};
    vector<int> first, second;
    vector<int> dp1(arr.size(), -1);
    vector<int> dp2(arr.size(), -1);
    for (int i = 0; i < arr.size(); i++)
    {
        if (i != arr.size() - 1)
        {
            first.push_back(arr[i]);
        }
        if (i != 0)
        {
            second.push_back(arr[i]);
        }
    }
    cout << max(f(first, 0, dp1), f(second, 0, dp2));
}