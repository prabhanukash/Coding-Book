#include <iostream>
#include <vector>
using namespace std;

int longestDecreasingSubsequence(int arr[], int n, vector<int> &dp) {
  dp[0] = 1;
  int ans = 1;

  for (int i = 1; i < n; i++) {
    int mx = 0;
    for (int j = 0; j < i; j++) {
      if (arr[j] > arr[i]) {
        mx = max(dp[j], mx);
      }
    }
    dp[i] = mx + 1;
    ans = max(ans, dp[i]);
  }

  return ans;
}
int longestIncreasingSubsequence(int arr[], int n, vector<int> &dp) {
  dp[0] = 1;
  int ans = 1;

  for (int i = 1; i < n; i++) {
    int mx = 0;
    for (int j = 0; j < i; j++) {
      if (arr[j] < arr[i]) {
        mx = max(dp[j], mx);
      }
    }
    dp[i] = mx + 1;
    ans = max(ans, dp[i]);
  }

  return ans;
}
int longestBitonicSubsequence(int arr[], int n) {
  vector<int> dp1(n, 0), dp2(n, 0);
  longestIncreasingSubsequence(arr, n, dp1);
  longestDecreasingSubsequence(arr, n, dp2);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, dp1[i] + dp2[i] -1);
  }
  return ans;
}
int main() {
  int arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Length of LBS is " << longestBitonicSubsequence(arr, n) << endl;
  return 0;
}
