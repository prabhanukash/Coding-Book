#include <bits/stdc++.h>
using namespace std;
int minAmountToReachN(int *arr, int n, int idx)
{
    if (idx == n - 1)
        return 0;
    if (idx == n - 2)
        return (arr, n, idx + 1) + abs(arr[idx] - arr[idx + 1]);
    int sp1 = minAmountToReachN(arr, n, idx + 1) + abs(arr[idx] - arr[idx + 1]);
    int sp2 = minAmountToReachN(arr, n, idx + 2) + abs(arr[idx] - arr[idx + 2]);

    return min(sp1, sp2);
}
int main()
{
    int arr[] = {10, 30, 40, 20};
    cout << minAmountToReachN(arr, 4, 0);
    return 0;
}