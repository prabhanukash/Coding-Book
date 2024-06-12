#include <bits/stdc++.h>
using namespace std;
void f(vector<int> &arr, int idx, int tar, vector<int> &comb, vector<vector<int>> &ans)
{
    if (idx == arr.size())
    {
        if (tar == 0)
        {
            ans.push_back(comb);
        }
        return;
    }
    if (arr[idx] <= tar)
    {
        comb.push_back(arr[idx]);
        f(arr, idx+1, tar - arr[idx], comb, ans);
        comb.pop_back();
    }
    //skip
    while(idx+1<arr.size() && arr[idx]==arr[idx+1])
        idx++;
    f(arr, idx + 1, tar, comb, ans);
}
int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> ans;
    vector<int> comb;
    sort(arr.begin(), arr.end());
    f(arr, 0, target, comb, ans);
    for (vector<int> &v : ans)
    {
        cout << "[";
        for (int i : v)
        {
            cout << i << ",";
        }
        cout << "]\n";
    }
}