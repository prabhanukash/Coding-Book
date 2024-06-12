#include <bits/stdc++.h>
using namespace std;

void f(vector<int> &nums, int idx, vector<vector<int>> &ans)
{
    if (idx == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    unordered_set<int> st;
    for (int i = idx; i < nums.size(); i++)
    {
        if(st.count(nums[i])==0){
            st.insert(nums[i]);
            swap(nums[i], nums[idx]);
            f(nums, idx + 1, ans);
            swap(nums[i], nums[idx]);
        }
    }
}
int main()
{
    vector<int> nums(3);
    nums = {1, 1, 2};
    vector<vector<int>> ans;
    f(nums, 0, ans);
    for (vector<int> &v : ans)
    {
        cout << "[";
        for (int val : v)
        {
            cout << val << ",";
        }
        cout << "]\n";
    }
    return 0;
}