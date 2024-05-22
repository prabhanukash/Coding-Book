#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &arr, int i, int j)
{
  while (i < j)
    swap(arr[i++], arr[j--]);
}
void nextPermutation(vector<int> &arr)
{
  int n = arr.size();
  int idx1 = n - 2;
  while (idx1 >= 0 and arr[idx1] >= arr[idx1 + 1])
    idx1--;
  if (idx1 >= 0)
  {
    int idx2 = n - 1;
    while (arr[idx2] <= arr[idx1])
      idx2--;
    swap(arr[idx1], arr[idx2]);
  }
  reverse(arr, idx1 + 1, n - 1);
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  nextPermutation(arr);
  for (int i = 0; i < n; i++)
    cout << arr[i] << ' ';
}