#include <bits/stdc++.h>
using namespace std;

void f(int start, int n, int k, vector<int> &comb, vector<vector<int>> &res)
{
    if (comb.size() == k)
    {
        res.push_back(comb);
        return;
    }
    for (int i = start; i <= n; i++)
    {
        comb.push_back(i);
        f(i + 1, n, k, comb, res);
        comb.pop_back();
    }
}
int main()
{
    vector<vector<int>> res;
    vector<int> comb;
    f(1, 4, 2, comb, res);
    for (vector<int> &v : res)
    {
        cout << "[";
        for (int val : v)
        {
            cout << val << ',';
        }
        cout << "]\n";
    }
    return 0;
    //TC: O(C(n, k))
    //SC: O(C(n, k))
}