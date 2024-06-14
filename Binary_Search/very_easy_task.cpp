// Problem Link - https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C
/* By Bhanu Prakash */
#include <bits/stdc++.h>
using namespace std;
long long n, x, y;
bool good(long long val)
{
	if (val < min(x, y)) return false;
	val -= min(x, y);
	return ((val / x) + (val / y) + 1 >= n);
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