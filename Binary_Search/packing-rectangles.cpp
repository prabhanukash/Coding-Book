// Problem Link - https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A
/* By Bhanu Prakash */
#include <bits/stdc++.h>
using namespace std;

long long w, h, n;

// Function to check if a square of side 'x' can fit at least 'n' rectangles of size 'w' x 'h'
bool good(long long x) {
    return (x / w) * (x / h) >= n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> w >> h >> n;

    long long l = 0; // bad
    long long r = 1; // good

    while (!good(r)) {
        r *= 2;
    }

    while (r > l + 1) {
        long long m = (l + r) / 2;  
        if (good(m)) {
            r = m;  
        } else {
            l = m; 
        }
    }

    cout << r << endl;
    return 0;
}
// Time Complexity: O(log(max side length))
// Space Complexity: O(1)