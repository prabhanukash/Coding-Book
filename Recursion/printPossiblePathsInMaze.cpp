#include <bits/stdc++.h>
using namespace std;
int totalPaths = 0;
void printPossiblePathsInMaze(int n, int m, int i, int j, string osf)
{
    if (i >= n or j >= m)
        return;
    if (i == n - 1 and j == m - 1)
    {
        cout << osf << endl;
        totalPaths++;
        return;
    }
    printPossiblePathsInMaze(n, m, i, j + 1, osf + "R");
    printPossiblePathsInMaze(n, m, i + 1, j, osf + "D");
    printPossiblePathsInMaze(n, m, i + 1, j + 1, osf + "->");
}
int main()
{
    printPossiblePathsInMaze(3, 3, 0, 0, "");
    cout << totalPaths << endl;
    return 0;
}