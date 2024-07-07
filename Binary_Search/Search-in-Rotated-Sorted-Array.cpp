// Problem Link - https://leetcode.com/problems/search-in-rotated-sorted-array/
/* By Bhanu Prakash */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int n = nums.size();
    int l = 0;
    int r = n - 1;

    while (l <= r) {
      int m = (l + r) >> 1; // Calculate the midpoint

      if (nums[m] == target)
        return m; // Target found at midpoint

      // Check if the left half is sorted
      if (nums[l] <= nums[m]) {
        // Check if target lies within the left half
        if (nums[l] <= target && target < nums[m]) {
          r = m - 1; // Adjust search to the left half
        } else {
          l = m + 1; // Adjust search to the right half
        }
      } else {
        // Right half is sorted
        // Check if target lies within the right half
        if (nums[m] < target && target <= nums[r]) {
          l = m + 1; // Adjust search to the right half
        } else {
          r = m - 1; // Adjust search to the left half
        }
      }
    }

    return -1; // Target not found
  }
};

int main() {
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
