// Problem Link - https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B
/* By Bhanu Prakash */
#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int n, k;
bool good(double len)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += floor(arr[i] / len);
    }
    return cnt >= k;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    double l = 0;
    double r = 1e8;
    for (int t = 0; t < 100; t++)
    {
        double m = (l + r) / 2;
        if (good(m))
        {
            l = m;
        }
        else
            r = m;
    }
    cout << setprecision(20) << l << endl;
    return 0;
}