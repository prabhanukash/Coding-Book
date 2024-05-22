#include <bits/stdc++.h>
using namespace std;

bool knows(vector<vector<int>> &arr, int a, int b)
{
  return arr[a][b] == 1;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  vector<vector<int>> arr(n, vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];
  }
  stack<int> st;
  for (int i = 0; i < n; i++) // O(n)->SC
    st.push(i);
  while (st.size() > 1)
  {
    int a = st.top();
    st.pop();
    int b = st.top();
    st.pop();
    if (knows(arr, a, b))
      st.push(b);
    else
      st.push(a);
  }
  int ans = st.top();
  int zero = 0, one = 0;
  for (int i = 0; i < n; i++) // O(n) TC
  {
    zero += arr[ans][i];
  }
  if (zero != 0)
  {
    cout << "-1\n";
    return 0;
  }
  for (int i = 0; i < n; i++) // O(n) TC
  {
    one += arr[i][ans];
  }
  if (one != n - 1)
  {
    cout << "-1\n";
    return 0;
  }
  cout << ans << '\n';
  /*
  TC: O(N)
  SC: O(N)
   */
  return 0;
}