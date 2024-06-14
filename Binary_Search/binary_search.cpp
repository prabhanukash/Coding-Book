// Problem Link - https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A
/* By Bhanu Prakash */
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	while (k--)
	{
		int x;
		cin >> x;
		int l = 0;
		int r = n - 1;
		bool ok = false;
		while (l <= r)
		{
			int m = (l + r) / 2;
			if (arr[m] == x)
			{
				ok = true;
				break;
			}
			else if (arr[m] < x)
				l = m + 1;
			else
				r = m - 1;
		}
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}