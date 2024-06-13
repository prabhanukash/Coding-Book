#include <bits/stdc++.h>
using namespace std;
bool isItSafe(vector<vector<bool>> &arr, int row, int col, int n)
{
	for (int i = row - 1; i >= 0; i--)
	{
		if (arr[i][col] == true)
			return false;
	}
	for (int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--)
		if (arr[i][j] == true)
			return false;
	for (int i = row - 1, j = col + 1; i >= 0 and j < n; i--, j++)
		if (arr[i][j] == true)
			return false;
	return true;
}
int countWays = 0;
void display(vector<vector<bool>> &arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j])
			{
				cout << "Q ";
			}
			else
			{
				cout << ". ";
			}
				}
		cout << endl;
	}
}
void countNQueen(vector<vector<bool>> &arr, int row, int n)
{
	if (row == n)
	{
		countWays++;
		display(arr, n);
		cout << "\n\n";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (isItSafe(arr, row, i, n))
		{
			arr[row][i] = true;
			countNQueen(arr, row + 1, n);
			arr[row][i] = false;
		}
	}
}
int main()
{
	int n;
	cin >> n;
	vector<vector<bool>> arr(n, vector<bool>(n));
	countNQueen(arr, 0, n);
	cout << countWays << endl;
	return 0;
}