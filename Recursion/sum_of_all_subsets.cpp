#include <bits/stdc++.h>
using namespace std;

void f(vector<int> &arr, int idx, int sum, vector<int> &ans)
{

    if (idx == arr.size())
    {
        ans.push_back(sum);
        return;
    }
    f(arr, idx + 1, sum + arr[idx], ans);
    f(arr, idx + 1, sum, ans);
}
int main()
{
    vector<int> arr(3);
    arr = {1,2,2};
    vector<int> ans;
    f(arr, 0, 0, ans);
    for (int val : ans)
        cout << val << ' ';
    return 0;
}