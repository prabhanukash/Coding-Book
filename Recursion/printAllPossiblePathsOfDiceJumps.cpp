#include<bits/stdc++.h>
using namespace std;
void printAllPossiblePathsOfDiceJumps(int n, int i, string osf)
{
    if (i >= n)
        return;
    if (i == n - 1)
    {
        cout << osf << endl;
        return;
    }
    for (int j = 1; j <= 6; j++)
    {
        printAllPossiblePathsOfDiceJumps(n, i + j, osf + to_string(j) + "->");
    }
}
int main(){

    printAllPossiblePathsOfDiceJumps(5,0,"");
    return 0;
}