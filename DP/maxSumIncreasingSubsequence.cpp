#include <iostream>
#include <vector>
using namespace std;

int maxSumIncreasingSubsequence(int arr[], int n) {
    vector<int> dp(n, 0);
    dp[0] = arr[0];
    int ans = 1; 

    for (int i = 1; i < n; i++) {
        int mx = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) { 
                mx = max(dp[j], mx);
            }
        }
        dp[i] = mx + arr[i];
        ans = max(ans, dp[i]);
    }

    return ans;
}

int main() {
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "maxSumIncreasingSubsequence is " << maxSumIncreasingSubsequence(arr, n) << endl;
    return 0;
}
