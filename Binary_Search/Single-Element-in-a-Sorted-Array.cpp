// https://leetcode.com/problems/single-element-in-a-sorted-array/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int singleNonDuplicate(vector<int> &nums) {
    int n = nums.size();
    // Boundary checks
    if (n == 1)
      return nums[0];
    if (nums[0] != nums[1])
      return nums[0];
    if (nums[n - 1] != nums[n - 2])
      return nums[n - 1];

    int l = 1;     // Start search from index 1
    int r = n - 2; // End search at index n-2
    while (l <= r) {
      int m = (l + r) >> 1; // Calculate midpoint
      // Check if the midpoint is the unique element
      if (nums[m] != nums[m - 1] && nums[m] != nums[m + 1])
        return nums[m];
      // Check the pattern of pairs
      if ((m % 2 == 0 && nums[m] == nums[m + 1]) ||
          (m % 2 != 0 && nums[m] == nums[m - 1])) {
        l = m + 1; 
      } else {
        r = m - 1; 
      }
    }
    return -1; // This line should never be reached if input is valid
  }
};

int main() {
  Solution solution;
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  int ans = solution.singleNonDuplicate(nums);
  cout << ans << endl;
  return 0;
}
