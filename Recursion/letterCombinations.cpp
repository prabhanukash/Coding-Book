#include <bits/stdc++.h>
using namespace std;
void f(string str, int i, string osf, vector<string> &result, vector<string> &v)
{
  if (i == str.size())
  {
    result.push_back(osf);
    return;
  }
  int digit = str[i] - '0';
  if (digit <= 1)
  {
    f(str, i + 1, osf, result, v);
  }
  for (int j = 0; j < v[digit].size(); j++)
  {
    f(str, i + 1, osf + v[digit][j], result, v);
  }
  return;
}
int main()
{
  vector<string> v(10);
  v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tvu", "wxyz"};
  vector<string> ans;
  f("258", 0, "", ans, v);
  for (string str : ans)
    cout << str << endl;
}