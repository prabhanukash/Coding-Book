//https://leetcode.com/problems/minimum-time-to-repair-cars/description/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Function to determine if all cars can be repaired in 'time' minutes
    bool good(vector<int> &ranks, long long time, int cars)
    {
        long long cnt = 0;
        for (int i = 0; i < ranks.size(); i++)
        {
            // Calculate the maximum number of cars a mechanic can repair in 'time' minutes
            cnt += floor(sqrt(time / ranks[i]));
        }
        // Check if the total number of cars that can be repaired is at least 'cars'
        return cnt >= cars;
    }

public:
    long long repairCars(vector<int> &ranks, int cars)
    {
        long long l = 0; // bad
        long long r = 1e18; // good
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
    long long ans = solution.repairCars(ranks, cars);
    cout << ans << endl; 
    return 0;
}
