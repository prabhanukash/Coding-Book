#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (r > l)
        {
            int m = (l + r) >> 1;
            if (m > 0 and m < n - 1)
            {
                if (nums[m] > nums[m - 1] and nums[m] > nums[m + 1])
                {
                    return m;
                }
                else if (nums[m - 1] > nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            }
            else if (m == 0)
            {
                if (nums[0] > nums[1])
                    return 0;
                else
                    return 1;
            }
            else if (m == n - 1)
            {
                if (nums[n - 1] > nums[n - 2])
                    return n - 1;
                else
                    return n - 2;
            }
        }
        return l;
    }
};
int main()
{
    Solution solution;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int ans = solution.findPeakElement(nums);
    cout << ans << endl;
    return 0;
}