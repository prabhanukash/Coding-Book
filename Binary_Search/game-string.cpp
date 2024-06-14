#include <bits/stdc++.h>
using namespace std;
bool good(string &t, string &p, vector<int> &v, int m)
{
    int idx = 0;
    // Iterate over 't' and check if 'p' can still be formed
    for (int i = 0; i < t.size() && idx < p.size(); i++)
    {
        if (v[i] <= m)
            continue; // Skip the letters deleted in the first 'm' deletions
        if (t[i] == p[idx])
        {          // Check if the remaining letter matches the current character in 'p'
            idx++; // Move to the next character in 'p'
        }
    }
    // Check if all characters in 'p' were found
    return idx == p.size();
}
int main()
{
    string t, p;
    cin >> t >> p;
    vector<int> arr(t.size());
    int x;
    for (int i = 1; i <= t.size(); i++)
    {
        cin >> x;
        arr[x - 1] = i;
    }
    int l = 0;
    int r = t.size();
    while (r > l + 1)
    {
        int m = (l + r) >> 1;
        if (good(t, p, arr, m))
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    cout << l << endl;
    return 0;
}