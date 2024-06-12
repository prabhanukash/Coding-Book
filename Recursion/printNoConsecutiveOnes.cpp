#include <bits/stdc++.h>
using namespace std;

void printNoConsecutiveOnes(int n, int idx, string osf)
{
    if (idx == n)
    {
        cout << osf << endl;
        return;
    }
    printNoConsecutiveOnes(n, idx + 1, osf + "0");
    if (osf.back() != '1' || osf.empty())
        printNoConsecutiveOnes(n, idx + 1, osf + "1");
}
int main()
{
    printNoConsecutiveOnes(3, 0, "");
    return 0;
}