#include <bits/stdc++.h>
using namespace std;

int KthSmallestInRowWiseSorted(vector<vector<int>> &arr, int n, int m, int k)
{
	priority_queue<pair<int, pair<int, int>>> pq;
	for (int i = 0; i < n; i++)
	{
		pq.push({-arr[i][0], {i, 0}});
	}
	k--;
	while (k)
	{
		pair<int, pair<int, int>> p = pq.top();
		int i = p.second.first;
		int j = p.second.second;
		pq.pop();
		k--;
		if (j + 1 < m)
			pq.push({-arr[i][j + 1], {i, j + 1}});
	}
	return -pq.top().first;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> arr(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << KthSmallestInRowWiseSorted(arr, n, m, k);
	return 0;
}