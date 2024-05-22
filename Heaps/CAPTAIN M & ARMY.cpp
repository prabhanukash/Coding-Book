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
	int k;
	cin >> k;
	priority_queue<pair<int, int>> pq;
	for (int i = 1; i <= n; i++)
	{
		int val;
		cin >> val;
		pq.push({val, -i});
	}
	while (k--)
	{
		pair<int, int> p = pq.top();
		pq.pop();
		cout << -p.second << ' ';
		p.first--;
		if (p.first)
		{
			pq.push(p);
		}
	}
	return 0;
}