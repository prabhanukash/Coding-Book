#include <bits/stdc++.h>
using namespace std;
bool isItSafe(vector<vector<int>> &arr, int n, int i, int j, vector<vector<bool>> &visited)
{
	return (i >= 0 and j >= 0 and i < n and j < n and visited[i][j] == false);
}
void display(vector<vector<int>> &arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}
void printKnightsTour(vector<vector<int>> &arr, int n, int i, int j, int cnt, vector<vector<bool>> &visited)
{
	if (cnt == n * n - 1)
	{
		arr[i][j] = cnt;
		display(arr, n);
		cout << "\n\n";
		return;
	}
	int dx[8] = {-2, -2, -1, -1, 2, 2, 1, 1};
	int dy[8] = {1, -1, 2, -2, 1, -1, 2, -2};
	visited[i][j] = true;
	arr[i][j] = cnt;
	for (int k = 0; k < 8; k++)
	{
		if (isItSafe(arr, n, i + dx[k], j + dy[k], visited))
		{
			printKnightsTour(arr, n, i + dx[k], j + dy[k], cnt + 1, visited);
		}
	}
	arr[i][j] = -1;
	visited[i][j] = false;
}
int main()
{
	int n;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(n, -1));
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	printKnightsTour(arr, n, 0, 0, 0, visited);
}