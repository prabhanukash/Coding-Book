#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int f(int index, vector<int> &coins, int amount, vector<vector<int>> &dp) {
    if (index == 0) {
      if (amount % coins[0] == 0)
        return amount / coins[0];
      return 1e9;
    }
    if (dp[index][amount] != -1)
      return dp[index][amount];
    int sp1 = f(index - 1, coins, amount, dp);
    int sp2 = INT_MAX;
    if (amount >= coins[index]) {
      sp2 = 1 + f(index, coins, amount - coins[index], dp);
    }
    return dp[index][amount] = min(sp1, sp2);
  }
  int coinChange(vector<int> &coins, int amount) {
    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
    int ans = f(coins.size() - 1, coins, amount, dp);
    if (ans >= 1e9)
      return -1;
    return ans;
  }
};
int main() {
  Solution solution;
  vector<int> coins = {1, 2, 3};
  int amount = 12;
  int ans = solution.coinChange(coins, amount);
  cout << ans << endl;
  return 0;
}