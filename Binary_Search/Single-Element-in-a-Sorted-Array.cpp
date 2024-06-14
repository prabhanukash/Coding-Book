// Problem Link - https://leetcode.com/problems/single-element-in-a-sorted-array/description/
/* By Bhanu Prakash */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int singleNonDuplicate(vector<int> &nums)
	{
		int n = nums.size();
		if (n == 1)
			return nums[0];
		if (nums[0] != nums[1])
			return nums[0];
		if (nums[n - 1] != nums[n - 2])
			return nums[n - 1];

		int l = 0;
		int r = n - 2;
		while (l <= r)
		{
			int m = (l + r) >> 1;
			if (nums[m] != nums[m - 1] and nums[m] != nums[m + 1])
				return nums[m];
			if ((m % 2 == 0 and nums[m] == nums[m + 1]) or
				(m % 2 and nums[m] == nums[m - 1]))
			{
				l = m + 1;
			}
			else
			{
				r = m - 1;
			}
		}
		return -1;
	}
};

int main()
{
	Solution solution;
	int n;
	cin >> n;
	vector<int> nums(n);
	int ans = solution.singleNonDuplicate(nums);
	return 0;
}