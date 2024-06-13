#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int skip[10][10];

    void helper(vector<bool> &vis, int curr, int remDigits, vector<int> &pattern, vector<vector<int>> &result)
    {
        if (remDigits < 0)
            return;
        if (remDigits == 0)
        {
            result.push_back(pattern); // Store the current valid pattern
            return;
        }

        vis[curr] = true; // Mark current key as visited
        for (int i = 1; i <= 9; i++)
        { // Try all possible next keys
            if (!vis[i] && (skip[curr][i] == 0 || vis[skip[curr][i]]))
            { // Check if move is valid
                pattern.push_back(i);
                helper(vis, i, remDigits - 1, pattern, result); // Recurse with next key
                pattern.pop_back();
            }
        }
        vis[curr] = false; // Unmark current key for backtracking
    }

    vector<vector<int>> numberOfPatterns(int m, int n)
    {
        vector<vector<int>> result;
        vector<bool> vis(10, false);   // Visited array
        memset(skip, 0, sizeof(skip)); // Initialize skip matrix to 0

        // Define skipping keys
        skip[1][3] = skip[3][1] = 2;
        skip[1][7] = skip[7][1] = 4;
        skip[3][9] = skip[9][3] = 6;
        skip[7][9] = skip[9][7] = 8;
        skip[1][9] = skip[9][1] = skip[3][7] = skip[7][3] = 5;
        skip[2][8] = skip[8][2] = skip[4][6] = skip[6][4] = 5;

        for (int i = m; i <= n; i++)
        {
            vector<int> pattern;
            // Patterns starting from 1, 3, 7, 9 (symmetric)
            pattern.push_back(1);
            helper(vis, 1, i - 1, pattern, result);
            pattern.pop_back();

            pattern.push_back(3);
            helper(vis, 3, i - 1, pattern, result);
            pattern.pop_back();

            pattern.push_back(7);
            helper(vis, 7, i - 1, pattern, result);
            pattern.pop_back();

            pattern.push_back(9);
            helper(vis, 9, i - 1, pattern, result);
            pattern.pop_back();

            // Patterns starting from 2, 4, 6, 8 (symmetric)
            pattern.push_back(2);
            helper(vis, 2, i - 1, pattern, result);
            pattern.pop_back();

            pattern.push_back(4);
            helper(vis, 4, i - 1, pattern, result);
            pattern.pop_back();

            pattern.push_back(6);
            helper(vis, 6, i - 1, pattern, result);
            pattern.pop_back();

            pattern.push_back(8);
            helper(vis, 8, i - 1, pattern, result);
            pattern.pop_back();

            // Pattern starting from 5 (unique)
            pattern.push_back(5);
            helper(vis, 5, i - 1, pattern, result);
            pattern.pop_back();
        }

        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> patterns = solution.numberOfPatterns(1, 3);

    for (const auto &pattern : patterns)
    {
        for (int key : pattern)
        {
            cout << key << " ";
        }
        cout << endl;
    }
    return 0;
}
