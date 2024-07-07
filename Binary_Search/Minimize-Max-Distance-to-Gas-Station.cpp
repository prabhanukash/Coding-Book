// https://www.lintcode.com/problem/848/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  // Helper function to check if it's possible to add K stations with max
  // distance 'dist' between them
  bool good(vector<int> &stations, double dist, int k) {
    int cnt = 0;
    for (int i = 1; i < stations.size(); ++i) {
      double gap = stations[i] - stations[i - 1];
      cnt += floor(gap / dist);
    }
    return cnt <= k;
  }

public:
  double minmaxGasDist(vector<int> &stations, int k) {
    double l = 0;
    double r = 1e9;
    for (int t = 0; t < 100; t++) {
      double m = (l + r) / 2;
      if (good(stations, m, k)) {
        r = m;
      } else {
        l = m;
      }
    }
    return r;
  }
};
int main() {
  Solution solution;
  int n, k;
  cin >> n >> k;
  vector<int> stations(n);
  for (int i = 0; i < n; i++)
    cin >> stations[i];
  double ans = solution.minmaxGasDist(stations, k);
  cout << setprecision(10) << ans << endl;
}