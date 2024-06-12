#include <bits/stdc++.h>
using namespace std;

int editDistance(string s1, string s2, int n, int m)
{
    if (n == 0)
        return m;
    if (m == 0)
        return n;
    if (s1[n - 1] == s2[m - 1])
        return editDistance(s1, s2, n - 1, m - 1);
    return 1 + min({editDistance(s1, s2, n, m - 1), // insert
                    editDistance(s1, s2, n - 1, m - 1), //replace
                    editDistance(s1, s2, n - 1, m)}); //remove
}
int main()
{

    string s1 = "GEEXSFRGEEKKS";
    string s2 = "GEEKSFORGEEKS";
    cout << editDistance(s1, s2, s1.size(), s2.size());
}