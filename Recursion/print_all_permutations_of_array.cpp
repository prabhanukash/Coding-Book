#include <bits/stdc++.h>
using namespace std;

void f(vector<int> &nums, vector<int> &perm, vector<vector<int>> &ans,
       vector<bool> &freq)
{
    if (perm.size() == nums.size())
    {
        ans.push_back(perm);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (freq[i] == false)
        {
            freq[i] = true;
            int val = nums[i];
            perm.push_back(val);
            f(nums, perm, ans, freq);
            perm.pop_back();
            freq[i] = false;
        }
    }
}
void f1(vector<int> &nums, int idx, vector<vector<int>> &ans)
{
    if (idx == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[i], nums[idx]);
        f1(nums, idx+1, ans);
        swap(nums[i], nums[idx]);
    }
}
int main()
{
    vector<int> nums(3);
    nums = {1,2,3};
    vector<vector<int>> ans;
    // vector<int> perm;
    // vector<bool> used(nums.size(), false);

    // f(nums, perm, ans, used);
    f1(nums, 0, ans);
    for(vector<int>& v:ans){
        cout << "[";
        for(int val:v){
            cout << val << ",";
        }
        cout << "]\n";
    }
    return 0;
}