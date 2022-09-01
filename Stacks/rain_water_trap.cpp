#include <bits/stdc++.h>
using namespace std;

// using two pointer approach

int approach2(int arr[], int n)
{
	int l = 0;
	int r = n - 1;
	int res = 0;
	int lmax = 0;
	int rmax = 0;
	while (l <= r)
	{
		if (arr[l] <= arr[r])
		{
			if (arr[l] >= lmax)
				lmax = arr[l];
			else
			{
				res += lmax - arr[l];
			}
			l++;
		}
		else
		{
			if (arr[r] >= rmax)
				rmax = arr[r];
			else
			{
				res += rmax - arr[r];
			}
			r--;
		}
	}
	return res;
	/*
	TC:O(N)
	SC:O(1)

	 */
}

// using prefix max and suffix max
int approach1(int arr[], int n)
{
	int lmax[n];
	int rmax[n];
	lmax[0] = arr[0];
	rmax[n - 1] = arr[n - 1];
	for (int i = 1; i < n; i++)
		lmax[i] = max(lmax[i - 1], arr[i]);

	for (int i = n - 2; i >= 0; i--)
		rmax[i] = max(rmax[i + 1], arr[i]);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += min(lmax[i], rmax[i]) - arr[i];
	}
	return ans;
	/*
	TC:O(3*N)
	SC:O(2*N)
	 */
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << approach1(arr, n) << '\n';
	cout << approach2(arr, n) << '\n';
	return 0;
}