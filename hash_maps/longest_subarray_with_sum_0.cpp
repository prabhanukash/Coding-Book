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
		int ps = 0;
		map<int, int> mp;
		mp[0] = -1;
		int ans = 0;
		for(int i=0; i<n; i++){
			ps += arr[i];
			if(mp.count(ps))
				ans = max(ans, i - ps);
				else
					mp[ps];
		}
		cout << ans << '\n';
		return 0;
}