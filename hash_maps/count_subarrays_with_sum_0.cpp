#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int arr[n];
	map<int, int> mp;
	mp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int ps = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ps += arr[i];
		ans += mp[ps];
		mp[ps]++;
	}
	cout << ans << '\n';
	return 0;
}