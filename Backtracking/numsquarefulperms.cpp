#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int ans = 0;
    bool checksquareful(int x, int y)
    {
        double sq = sqrt(x + y);
        return (sq - floor(sq)) == 0;
    }
    void f(vector<int> &arr, int start)
    {
        if (start > 1 and (!checksquareful(arr[start - 2], arr[start - 1])))
        {
            return;
        }
        if (start == (arr.size() - 1) and
            !checksquareful(arr[start], arr[start - 1]))
        {
            return;
        }
        if (start == (arr.size() - 1))
        {
            ans++;
            return;
        }
        unordered_set<int> st;
        for (int i = start; i < arr.size(); i++)
        {
            if (st.count(arr[i]) > 0)
                continue;
            st.insert(arr[i]);
            swap(arr[i], arr[start]);
            f(arr, start + 1);
            swap(arr[i], arr[start]);
        }
    }

public:
    int numSquarefulPerms(vector<int> &nums)
    {
        f(nums, 0);
        return ans;
    }
};
int main()
{
    Solution solution;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << solution.numSquarefulPerms(arr);
    return 0;
}
