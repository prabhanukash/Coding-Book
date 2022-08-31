#include <bits/stdc++.h>
using namespace std;
int skip[10][10];
int helper(vector<bool> &visited, int currDigit, int remainingDigits)
{
  if (remainingDigits < 0)
    return 0;
  if (remainingDigits == 0)
    return 1;
  visited[currDigit] = true;
  int result = 0;
  for (int i = 1; i <= 9; i++)
  {
    if (not visited[i] and (skip[currDigit][i] == 0 or visited[skip[currDigit][i]] == true))
    {
      result += helper(visited, i, remainingDigits - 1);
    }
  }
  visited[currDigit] = false;
  return result;
}
int countPatterns(int m, int n)
{
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      skip[i][j] = 0;
    }
  }
  skip[1][3] = skip[3][1] = 2;
  skip[1][7] = skip[7][1] = 4;
  skip[9][3] = skip[3][9] = 6;
  skip[9][7] = skip[7][9] = 8;
  skip[1][9] = skip[9][1] = skip[3][7] = skip[7][3] = skip[2][8] = skip[8][2] = skip[4][6] = skip[6][4] = 5;
  vector<bool> visited(10, false);
  int result = 0;
  for (int i = m; i <= n; i++)
  {
    result += helper(visited, 1, i - 1) * 4; // symmetry for 1,3,7,9
    result += helper(visited, 2, i - 1) * 4; // symmetry for 1,3,7,9
    result += helper(visited, 5, i - 1);     // symmetry for 1,3,7,9
  }
  return result;
}
vector<string> allpattern;
int helper(vector<bool> &visited, int currDigit, int remainingDigits, string output)
{
  if (remainingDigits < 0)
    return 0;
  if (remainingDigits == 0)
  {
    allpattern.push_back(output);
    return 1;
  }
  visited[currDigit] = true;
  int result = 0;
  for (int i = 1; i <= 9; i++)
  {
    if (not visited[i] and (skip[currDigit][i] == 0 or visited[skip[currDigit][i]] == true))
    {
      result += helper(visited, i, remainingDigits - 1, output + to_string(i));
    }
  }
  visited[currDigit] = false;
  return result;
}

int printPatterns(int m, int n, string output)
{
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      skip[i][j] = 0;
    }
  }
  skip[1][3] = skip[3][1] = 2;
  skip[1][7] = skip[7][1] = 4;
  skip[9][3] = skip[3][9] = 6;
  skip[9][7] = skip[7][9] = 8;
  skip[1][9] = skip[9][1] = skip[3][7] = skip[7][3] = skip[2][8] = skip[8][2] = skip[4][6] = skip[6][4] = 5;
  vector<bool> visited(10, false);
  int result = 0;
  for (int i = m; i <= n; i++)
  {
    result += helper(visited, 1, i - 1, output + "1");
    result += helper(visited, 2, i - 1, output + "2");
    result += helper(visited, 3, i - 1, output + "3");
    result += helper(visited, 4, i - 1, output + "4");
    result += helper(visited, 5, i - 1, output + "5");
    result += helper(visited, 6, i - 1, output + "6");
    result += helper(visited, 7, i - 1, output + "7");
    result += helper(visited, 8, i - 1, output + "8");
    result += helper(visited, 9, i - 1, output + "9");
  }
  return result;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cout << printPatterns(1, 3, "") << '\n';
    for (string str : allpattern)
    {
      cout << str << '\n';
    }
    return 0;
}