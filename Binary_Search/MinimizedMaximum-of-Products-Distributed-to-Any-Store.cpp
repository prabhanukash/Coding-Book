//https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Function to check if it's possible to distribute products such that max is <= x
    bool good(vector<int>& quantities, int x, int n) {
        int cnt = 0;
        for (int val : quantities) {
            cnt += ceil((double)val / (double)x);
        }
        return cnt <= n;
    }

public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1; // bad
        int r = *max_element(quantities.begin(), quantities.end()); // good
        int ans = 0;

       
        while (l <= r) {
            int m = (l + r) >> 1; 
            if (good(quantities, m, n)) {
                ans = m; 
                r = m - 1; 
            } else {
                l = m + 1; 
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    int n, m;
    cin >> n >> m;
    vector<int> quantities(m);
    for (int i = 0; i < m; i++)
        cin >> quantities[i]; 
    int ans = solution.minimizedMaximum(n, quantities);
    cout << ans << endl; 
    return 0;
}
