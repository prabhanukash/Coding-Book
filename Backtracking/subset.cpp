#include <bits/stdc++.h>
using namespace std;

void printSubsets(vector<int> &arr, int idx, vector<int> &subsets, vector<vector<int>> &ans)
{
    if (idx == arr.size())
    {
        ans.push_back(subsets);
        return;
    }
    subsets.push_back(arr[idx]);
    printSubsets(arr, idx + 1, subsets, ans);
    subsets.pop_back();
    printSubsets(arr, idx + 1, subsets, ans);
}
int main()
{
    vector<int> arr(3);
    arr = {1, 2, 3};
    vector<int> subsets;
    vector<vector<int>> ans;
    printSubsets(arr, 0, subsets, ans);
    for (vector<int> &v : ans)
    {
        cout << "[";
        for (int val : v)
            cout << val << ",";
        cout << "]\n";
    }
    return 0;
}