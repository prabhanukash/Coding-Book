#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool good(vector<int> &sweetness, int tar, int k)
    {
        int cnt = 0;
        int sum = 0;
        for (int val : sweetness)
        {
            if (sum + val >= tar)
            {
                sum = 0;
                cnt++;
            }
            else
            {
                sum += val;
            }
        }
        return cnt >= k;
    }

public:
    int maximizeSweetness(vector<int> &sweetness, int k)
    {
        int l = 1;
        int r = 1e9;
        while (r > l + 1)
        {
            int m = (l + r) >> 1;
            if (good(sweetness, m, k + 1))
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        return l;
    }
};
int main()
{
    Solution solution;
    int n, k;
    cin >> n >> k;
    vector<int> sweetness(n);
    for (int i = 0; i < n; i++)
        cin >> sweetness[i];
    int ans = solution.maximizeSweetness(sweetness, k);
    cout << ans << endl;
    return 0;
}