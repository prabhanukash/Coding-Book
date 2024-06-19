#include <bits/stdc++.h>
using namespace std;

vector<int> spiralPrint(vector<vector<int>> &arr)
{
    vector<int> result;
    int n = arr.size();
    int m = arr[0].size();
    int l = 0, r = m - 1;
    int t = 0, d = n - 1;

    while (l <= r && t <= d)
    {
        // Traverse from left to right
        for (int j = l; j <= r; ++j)
        {
            result.push_back(arr[t][j]);
        }
        t++; // move down to the next row

        // Traverse from top to bottom
        for (int i = t; i <= d; ++i)
        {
            result.push_back(arr[i][r]);
        }
        r--; // move left to the next column

        // Check if there are still rows and columns left
        if (t <= d)
        {
            // Traverse from right to left
            for (int j = r; j >= l; --j)
            {
                result.push_back(arr[d][j]);
            }
            d--; // move up to the next row
        }

        if (l <= r)
        {
            // Traverse from bottom to top
            for (int i = d; i >= t; --i)
            {
                result.push_back(arr[i][l]);
            }
            l++; // move right to the next column
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> arr{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        };

    vector<int> result = spiralPrint(arr);
    for (int x : result)
    {
        cout << x << " ";
    }
    return 0;
}
