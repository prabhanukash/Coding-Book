#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  // Function to check if `val * val` is less than or equal to `n`
  bool good(int n, long long val) {
    long long sqrt = val * val;
    return sqrt <= n;
  }

public:
  int mySqrt(int x) {
    if (x <= 1) // Handle edge cases where x is 0 or 1
      return x;

    int l = 0; // good
    int r = x; // bad

    while (r > l + 1) {
      long long m = (l + r) >> 1;
      if (good(x, m)) {
        l = m;
      } else {
        r = m;
      }
    }
    return l;
  }
};

int main() {
  Solution solution;
  int n;
  cin >> n;
  int ans = solution.mySqrt(n);
  cout << ans;
}
