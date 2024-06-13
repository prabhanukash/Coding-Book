#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec, fact(n + 1);
    fact[0] = 1;
    int sum = 1;
    for (int i = 1; i <= n; i++)
    {
        sum *= i;
        fact[i] = sum;
        vec.push_back(i);
    }
    k--;
    string str = "";
    for (int i = 1; i <= n; i++)
    {
        int idx = k / fact[n - i];
        k %= fact[n - i];
        str += to_string(vec[idx]);
        vec.erase(vec.begin() + idx);
    }
    cout << str << endl;
    return 0;
}