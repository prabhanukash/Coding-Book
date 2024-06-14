#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool good(vector<int> &weights, int currentCapacity, int days)
    {
        int d = 1;
        int currentTotalWeight = 0;
        for (auto w : weights)
        {
            if (w + currentTotalWeight <= currentCapacity)
            {
                currentTotalWeight += w;
            }
            else
            {
                d++;
                currentTotalWeight = w;
                if (w > currentCapacity)
                {
                    return false;
                }
            }
        }
        return d <= days;
    }

public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int l = 1;
        int r = 1e9;
        while (r > l + 1)
        {
            int m = (l + r) >> 1;
            if (good(weights, m, days))
            {
                r = m;
            }
            else
            {
                l = m;
            }
        }
        return r;
    }
};
int main()
{
    Solution solution;
    int n, days;
    cin >> n >> days;
    vector<int> weights(n);
    for (int i = 0; i < n; i++)
        cin >> weights[i];
    
    int ans = solution.shipWithinDays(weights, days);
    cout << ans << endl;

    return 0;
}