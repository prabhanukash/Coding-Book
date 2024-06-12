#include <bits/stdc++.h>
using namespace std;
void printSubsets(int *arr, int idx, int n, string osf)
{
    if (idx == n)
    {
        cout << "[" + osf + "]" << endl;
        return;
    }
    printSubsets(arr, idx + 1, n, osf + to_string(arr[idx]));
    printSubsets(arr, idx + 1, n, osf);
}
int main()
{

    int arr[] = {1, 2, 3};
    printSubsets(arr, 0, 3, "");
}