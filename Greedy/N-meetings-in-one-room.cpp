#include <bits/stdc++.h>
using namespace std;
bool cmp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}
int main()
{
    vector<vector<int>> arr(3);
    arr = {{10, 20}, {12, 25}, {20, 30}};
    sort(arr.begin(), arr.end(), cmp);
    int lastEndTime = arr[0][1];
    int cnt = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i][0] > lastEndTime)
        {
            cnt++;
            lastEndTime = arr[i][1];
        }
    }
    cout << cnt << endl;
    return 0;
}