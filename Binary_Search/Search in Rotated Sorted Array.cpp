/*
rotated at unkown position at k

[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]

[0,1,2,4,5,6,7] might be rotated at pivot index 3 and become

target = 0
ans = 4

target need to be search in the given rotated array
 0 1 2 3 4 5 6
[4,5,6,7,0,1,2]
				 se
 */

#include <bits/stdc++.h>
using namespace std;

int findInRotatedArray(int arr[], int n, int tar)
{

	int s = 0;
	int e = n - 1;
	while (s <= e)
	{
		int m = (s + e) / 2;
		if (arr[m] == tar)
			return m;
		if (arr[s] <= arr[m])
		{
			if (tar >= arr[s] and tar <= arr[e])
			{
				e = m - 1;
			}
			else
				s = m + 1;
		}
		else
		{
			if (tar >= arr[m] and tar <= arr[e])
			{
				s = m + 1;
			}
			else
				e = m - 1;
		}
	}
	return -1;
	/*
	TC:O(log(N))
	SC:O(1)
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
	int tar;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> tar;
	cout << findInRotatedArray(arr, n, tar);
	return 0;
}