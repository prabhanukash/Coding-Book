#include <bits/stdc++.h>
using namespace std;
int totalPaths = 0;
bool isSafe(int n, int m, int i, int j, vector<vector<bool>> &visited)
{
	return i >= 0 and i < n and j >= 0 and j < m and visited[i][j] == false;
}
void helper(int n, int m, vector<vector<int>> &arr, int i, int j, vector<vector<bool>> &visited)
{
	if (i == n - 1 and j == m - 1)
	{
		totalPaths++;
		return;
	}
	if (not isSafe(n, m, i, j, visited))
		return;
	visited[i][j] = true;
	if (j - 1 >= 0 and arr[i][j - 1] == 0)
		helper(n, m, arr, i, j - 1, visited);
	if (i + 1 < n and arr[i + 1][j] == 0)
		helper(n, m, arr, i + 1, j, visited);
	if (j + 1 < m and arr[i][j + 1] == 0)
		helper(n, m, arr, i, j + 1, visited);
	if (i - 1 >= 0 and arr[i - 1][j] == 0)
		helper(n, m, arr, i - 1, j, visited);
	visited[i][j] = false;
	return;
}
int countPathsInMaze(vector<vector<int>> &maze)
{
	int n = maze.size();
	int m = maze[0].size();
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	helper(n, m, maze, 0, 0, visited);
	return totalPaths;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << countPathsInMaze(arr) << endl;
	return 0;
}