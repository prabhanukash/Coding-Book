#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    int start = 0;
    int end = s.size() - 1;
    while (start <= end)
    {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}
void f(string str, string osf)
{
    if (str.empty())
    {
        cout << osf << endl;
        return;
    }
    for (int i = 0; i < str.size(); i++)
    {
        string prefix = str.substr(0, i + 1);
        string ros = str.substr(i + 1);
        if (isPalindrome(prefix))
        {
            f(ros, osf + "(" + prefix + ")");
        }
    }
}
int main()
{
    f("aaa", "");
    return 0;
}