#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int skip[10][10];
    int helper(vector<bool> &vis, int curr, int remDigits)
    {
        if (remDigits < 0)
            return 0;
        if (remDigits == 0)
            return 1;
        vis[curr] = true;
        int ans = 0;
        for (int i = 1; i <= 9; i++)
        {
            // if nextNum is not visited and (curNum is adjacent to nextNum or their skip number is visited)
            if (vis[i] == false and (skip[curr][i] == 0 or vis[skip[curr][i]] == true))
            {
                ans += helper(vis, i, remDigits - 1);
            }
        }
        vis[curr] = false;
        return ans;
    }
public:
    int numberOfPatterns(int m, int n)
    {
        int ans = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                skip[i][j] = 0;
            }
        }
        // Skip represents the number to skip between two numbers
        skip[1][3] = skip[3][1] = 2;
        skip[1][7] = skip[7][1] = 4;
        skip[9][3] = skip[3][9] = 6;
        skip[9][7] = skip[7][9] = 8;
        skip[1][9] = skip[9][1] = skip[3][7] = skip[7][3] = skip[2][8] = skip[8][2] = skip[4][6] = skip[6][4] = 5;
        vector<bool> vis(10, false);
        for (int i = m; i <= n; i++)
        {
            ans += helper(vis, 1, i - 1) * 4; // 1, 3, 7, 9 are symmetric
            ans += helper(vis, 2, i - 1) * 4; // 2, 4, 6, 8 are symmetric
            ans += helper(vis, 5, i - 1);
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    int patterns = solution.numberOfPatterns(2, 2);
    cout << patterns << endl;
    return 0;
    
}
