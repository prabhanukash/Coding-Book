#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool f(vector<int> &nums, int index, int target, vector<vector<int>> &dp) {
    if (target == 0)
      return true;
    if (index == 0) {
      return target == nums[0];
    }
    if (dp[index][target] != -1)
      return dp[index][target];
    bool sp1 = f(nums, index - 1, target, dp);
    bool sp2 = false;
    if (nums[index] <= target) {
      sp2 = f(nums, index - 1, target - nums[index], dp);
    }
    return dp[index][target] = sp1 | sp2;
  }
  bool canPartition(vector<int> &nums) {
    int n = nums.size();
    int sum = 0;
    for (int val : nums)
      sum += val;
    if (sum % 2)
      return false;
    vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, -1));
    return f(nums, n - 1, sum / 2, dp);
  }
};
int main() {
  Solution solution;
  vector<int> nums = {1, 6, 11, 5};
  cout << solution.canPartition(nums) << endl;
  return 0;
}