// https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/A
#include <bits/stdc++.h>
using namespace std;

struct citizen {
  int x_position, speed;
};

// Function to check if all citizens can gather within 'time' seconds
bool good(vector<citizen> &citizens, int n, double time) {
  double L = -1e10;
  double R = 1e10;
  for (int i = 0; i < n; i++) {
    double xl = citizens[i].x_position - time * citizens[i].speed;
    double xr = citizens[i].x_position + time * citizens[i].speed;

    L = max(L, xl);
    R = min(R, xr);

    if (L > R) {
      return false;
    }
  }

  return true;
}
int main() {
  int n;
  cin >> n;
  vector<citizen> citizens(n);

  for (auto &citizen : citizens)
    cin >> citizen.x_position >> citizen.speed;

  double l = 0;
  double r = 1e18;
  for (int i = 0; i < 100; i++) {
    double m = (l + r) / 2;
    if (good(citizens, n, m)) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << setprecision(10) << r << endl;
}

// Time Complexity: O(nlogM)
// Space Complexity: O(n)