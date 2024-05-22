#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  string str;
  cin >> str;
  int n = str.size();
  int k;
  cin >> k;
  map<char, int> mp;
  for (int i = 0; i < n; i++)
    mp[str[i]]++;
  priority_queue<int> pq;
  for (auto i : mp)
  {
    pq.push(i.second);
  }
  while (k > 0)
  {

    int val = pq.top();
    pq.pop();
    k--;
    pq.push(val - 1);
  }
  int ans = 0;
  while (pq.size() > 0)
  {
    int val = pq.top();
    pq.pop();
    ans += (val) * (val);
  }
  cout << ans << '\n';
  return 0;
}