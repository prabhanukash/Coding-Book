// Problem Link - https://leetcode.com/problems/search-in-rotated-sorted-array/
/* By Bhanu Prakash */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int search(vector<int> &nums, int target)
	{
		int l = 0;
		int r = nums.size() - 1;
		while (l <= r)
		{
			int m = (l + r) >> 1;
			if (target == nums[m])
				return m;
			if (nums[l] <= nums[m])
			{
				if (target <= nums[m] and target >= nums[l])
				{
					r = m - 1;
				}
				else
				{
					l = m + 1;
				}
			}
			else
			{
				if (target >= nums[m] and target <= nums[r])
				{
					l = m + 1;
				}
				else
				{
					r = m - 1;
				}
			}
		}
		return -1;
	}
};
int main()
{
	Solution solution;
	int n, target;
	cin >> n >> target;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	int ans = solution.search(nums, target);
	cout << ans << endl;
	return 0;
}