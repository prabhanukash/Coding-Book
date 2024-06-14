#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool good(vector<int> &ranks, long long time, int cars)
    {
        long long cnt = 0;
        for (int i = 0; i < ranks.size(); i++)
        {
            cnt += floor(sqrt(time / ranks[i]));
        }
        return cnt >= cars;
    }

public:
    long long repairCars(vector<int> &ranks, int cars)
    {
        long long l = 0;
        long long r = 1e18;
        while (r > l + 1)
        {
            long long m = (l + r) >> 1;
            if (good(ranks, m, cars))
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
    int n, cars;
    cin >> n >> cars;
    vector<int> ranks(n);
    for (int i = 0; i < n; i++)
        cin >> ranks[i];
    int ans = solution.repairCars(ranks, cars);
    cout << ans << endl;
}