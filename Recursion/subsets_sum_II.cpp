#include <bits/stdc++.h>
using namespace std;
void f(vector<int> &arr, int idx, vector<int> &subset, vector<vector<int>> &ans)
{
    if (idx == arr.size())
    {
        ans.push_back(subset);
        return;
    }
    subset.push_back(arr[idx]);
    f(arr, idx + 1, subset, ans);
    subset.pop_back();
    while (idx + 1 < arr.size() && arr[idx] == arr[idx + 1])
        idx++;
    f(arr, idx + 1, subset, ans);
}
int main()
{
    vector<int> arr(3);
    arr = {1, 2, 2};
    vector<vector<int>> ans;
    vector<int> subset;
    f(arr, 0, subset, ans);
    for (vector<int> &v : ans)
    {
        cout << "[";
        for (int val : v)
            cout << val << ",";
        cout << "]\n";
    }
    return 0;
}