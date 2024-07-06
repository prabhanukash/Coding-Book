#include <iostream>
#include <vector>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n) {
    vector<int> dp(n, 0);
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

int main() {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Length of LIS is " << longestIncreasingSubsequence(arr, n) << endl;
    return 0;
}
