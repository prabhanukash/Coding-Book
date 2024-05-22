#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
  if (n == 1 or n == 0)
    return 1;

  int sp1 = fact(n - 1);
  return n * sp1;
}
int fib(int n)
{
  if (n <= 1)
    return n;
  int sp1 = fib(n - 1);
  int sp2 = fact(n - 2);
  return sp1 + sp2;
}
void printNaturalNumber(int n)
{
  if (n == 1)
  {
    cout << n << '\n';
    return;
  }
  cout << n << '\n';
  printNaturalNumber(n - 1);
  cout << n << '\n';
}
int NoConsecutiveOnes(int n)
{
  if (n == 1)
    return 2;
  if (n == 2)
    return 3;
  int sp1 = fib(n - 1);
  int sp2 = fact(n - 2);
  return sp1 + sp2;
}
int friendsPairing(int n)
{

  if (n <= 2)
    return n;

  int sp1 = 1 * friendsPairing(n - 1);
  int sp2 = (n - 1) * friendsPairing(n - 2);
  return sp1 + sp2;
}
int recPow(int n, int m)
{
  if (m == 0)
    return 1;
  int sp1 = n * recPow(n, m - 1);
  return sp1;
}
int powRec(int n, int m)
{
  if (m == 0)
    return 1;
  if (m == 1)
    return n;
  int tmp = powRec(n, m / 2);
  if (m % 2)
    return n * tmp * tmp;
  else
    return tmp * tmp;
}
void printPattern(int n, int i)
{
  if (n == 0)
    return;
  if (i < n)
  {
    cout << "* ";
    printPattern(n, i + 1);
  }
  else
  {
    cout << '\n';
    printPattern(n - 1, 0);
  }
}
void printSubsets(vector<int> &arr, int i, int n, string osf)
{
  if (i == n)
  {
    cout << "[" + osf + "]" << '\n';
    return;
  }
  printSubsets(arr, i + 1, n, osf + to_string(arr[i]) + ",");
  printSubsets(arr, i + 1, n, osf);
}
int totPaths = 0;
void mazePath(int i, int j, int n, int m, string osf)
{
  if (i == n - 1 and j == m - 1)
  {
    totPaths += 1;
    cout << osf << '\n';
    return;
  }
  if (i >= n or j >= m)
    return;
  mazePath(i, j + 1, n, m, osf + "R");
  mazePath(i + 1, j, n, m, osf + "D");
}
void dicePath(int n, int i, string osf)
{
  if (i >= n)
    return;
  if (i == n - 1)
  {
    cout << osf << '\n';
    return;
  }
  for (int j = 1; j <= 6; j++)
  {
    dicePath(n, i + j, osf + to_string(j) + "->");
  }
}
void lexico(int i, int n)
{
  if (i > n)
    return;
  cout << i << '\n';
  for (int j = (i == 0) ? 1 : 0; j <= 9; j++)
  {
    lexico(10 * i + j, n);
  }
}
vector<string> calculateMirror(int n, int m)
{
  if (n == 0)
    return {""};
  if (n == 1)
    return {"0", "1", "8"};
  vector<string> temp = calculateMirror(n - 2, m);
  vector<string> res;
  for (string s : temp)
  {
    if (n != m)
      res.push_back("0" + s + "0");
    res.push_back("1" + s + "1");
    res.push_back("6" + s + "9");
    res.push_back("8" + s + "8");
    res.push_back("9" + s + "6");
  }
  return res;
}
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
void solve(string digit, string output, int index, vector<string> &ans, string mapping[])
{

  if (index >= digit.size())
  {
    ans.push_back(output);
    return;
  }

  int number = digit[index] - '0';
  string value = mapping[number];

  for (int i = 0; i < value.size(); i++)
  {
    output.push_back(value[i]);
    solve(digit, output, index + 1, ans, mapping);
    output.pop_back();
  }
}
void printPermutations(string str, string osf)
{
  if (str.size() == 0)
  {
    cout << osf << '\n';
    return;
  }
  unordered_set<char> st;
  string ros = "";
  for (int i = 0; i < str.size(); i++)
  {
    char ch = str[i];
    if (st.count(ch))
      continue;
    ros = str.substr(0, i) + str.substr(i + 1);
    printPermutations(ros, osf + ch);
  }
}
vector<string> letterCombinations(string digits)
{
  vector<string> ans;
  if (digits.size() == 0)
    return ans;
  string output = "";
  int index = 0;

  string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

  solve(digits, output, index, ans, mapping);

  return ans;
}
void printPermutationsBT(string str, int j)
{
  if (j == str.size() - 1)
  {
    cout << str << '\n';
    return;
  }
  for (int i = j; i < str.size(); i++)
  {
    swap(str[i], str[j]);
    printPermutationsBT(str, j + 1);
    swap(str[i], str[j]);
  }
}
bool isSafe(int i, int j, int n, int m, vector<vector<bool>> &vis)
{
  return (i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == false);
}
void helper(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<bool>> &vis)
{
  if (i == n - 1 and j == m - 1)
  {
    totPaths++;
    return;
  }
  if (!isSafe(i, j, n, m, vis))
    return;

  vis[i][j] = true;
  if (i + 1 < n and grid[i + 1][j] == 0) // down
  {
    helper(i + 1, j, n, m, grid, vis);
  }
  if (j + 1 < m and grid[i][j + 1] == 0) // right
  {
    helper(i, j + 1, n, m, grid, vis);
  }
  if (i - 1 >= 0 and grid[i - 1][j] == 0) // up
  {
    helper(i - 1, j, n, m, grid, vis);
  }
  if (j - 1 >= 0 and grid[i][j - 1] == 0) // left
  {
    helper(i, j - 1, n, m, grid, vis);
  }
  vis[i][j] = false;
  return;
}
int countRatMaze(vector<vector<int>> &grid)
{
  int n = grid.size();
  int m = grid[0].size();
  totPaths = 0;
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  helper(0, 0, n, m, grid, vis);
  return totPaths;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  // cout << fact(5) << '\n';
  // cout << fib(4) << '\n';
  // printNaturalNumber(5);
  // cout << friendsPairing(3);
  // cout << powRec(2, 6);
  // printPattern(5, 0);
  // vector<int> arr = {1, 2, 3};
  // printSubsets(arr,0,arr.size(),"");
  // mazePath(0, 0, 3, 3, "");
  // cout << totPaths << '\n';
  // dicePath(4, 0, "");
  // lexico(0, 1005);
  // vector<string> ans = calculateMirror(2, 2);
  // for (string str : ans)
  // cout << str << '\n';
  // cout << printPatterns(1, 3,"")<<'\n';
  // for(string str:allpattern){
  //     cout << str << '\n';
  // }
  // vector<string> ans = letterCombinations("2");
  // for(string str:ans)
  //     cout << str << ' ';
  // printPermutationsBT("ABC", 0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> arr(n, vector<int>(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cin >> arr[i][j];
  }
  cout << countRatMaze(arr);
  return 0;
}