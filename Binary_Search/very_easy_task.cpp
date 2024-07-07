// Problem Link - https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C
/* By Bhanu Prakash */
#include <bits/stdc++.h>
using namespace std;
long long n, x, y;
// Function to check if `val` time is enough to produce `n` copies
bool good(long long val) {
		if (val < min(x, y)) return false; // If `val` is less than the time taken by the faster copier
		val -= min(x, y); // First copy is done by the faster copier
		return ((val / x) + (val / y) + 1 >= n); // Check if total copies including the first one is at least `n`
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> x >> y;
	long long l = 0;				 // bad
	long long  r = n * max(x, y); // good
	while (r > l + 1)
	{
		long long m = (l + r) >> 1;
		if (good(m))
		{
			r = m;
		}
		else
			l = m;
	}
	cout << r <<"\n";
	return 0;
}