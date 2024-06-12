#include <bits/stdc++.h>
using namespace std;
int powRec(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    int sp = powRec(a, b / 2);
    if (b % 2)
        return a * sp * sp;
    else
        return sp * sp;
}
int isArmstrongNumber(int n, int d)
{
    if (n == 0)
        return 0;
    return isArmstrongNumber(n / 10, d) + powRec(n % 10, d);
}
int main()
{
    int n = 153;
    if (isArmstrongNumber(153, 3) == n)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}