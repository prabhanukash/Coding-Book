#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
  // base case
  if (n == 1)
    return 1;

  // recursive assumption
  int sp = fact(n - 1);

  // self work
  return n * sp;
}
int fib(int n)
{
  if (n <= 1)
    return n;
  int sp1 = fib(n - 1);
  int sp2 = fib(n - 2);
  return sp1 + sp2;
}
void printFirstNNaturalNumbers(int n)
{
  if (n == 1)
  {
    cout << 1 << endl;
    return;
  }
  cout << n << endl;
  printFirstNNaturalNumbers(n - 1);
  cout << n << endl;
}
int friendsPairing(int n)
{

  if (n <= 2)
    return n;

  int sp1 = 1 * friendsPairing(n - 1);
  int sp2 = (n - 1) * friendsPairing(n - 2);
  return sp1 + sp2;
}
void pattern1(int n, int i)
{
  if (n == 0)
    return;
  if (i < n)
  {
    cout << "* ";
    pattern1(n, i + 1);
  }
  else
  {
    cout << endl;
    pattern1(n - 1, 0);
  }
}

void printNoConsecutiveOnes(int n, int i, string osf)
{
  if (i == n)
  {
    cout << osf << endl;
    return;
  }

  printNoConsecutiveOnes(n, i + 1, osf + "0");

  if (osf.empty() || osf.back() != '1')
  {
    printNoConsecutiveOnes(n, i + 1, osf + "1");
  }
}
void printPairingCombinations(vector<int> &friends, vector<bool> &used, string current)
{
  int n = friends.size();

  // Find the first unpaired friend
  int i;
  for (i = 0; i < n; ++i)
  {
    if (!used[i])
    {
      break;
    }
  }

  // Base case: if all friends are paired
  if (i == n)
  {
    cout << current << endl;
    return;
  }

  // Option 1: Person i stays single
  used[i] = true;
  printPairingCombinations(friends, used, current + " (" + to_string(friends[i]) + ")");

  // Option 2: Person i pairs with each of the remaining friends
  for (int j = i + 1; j < n; ++j)
  {
    if (!used[j])
    {
      used[j] = true;
      printPairingCombinations(friends, used, current + " (" + to_string(friends[i]) + "," + to_string(friends[j]) + ")");
      used[j] = false; // backtrack
    }
  }

  used[i] = false; // backtrack
}
void generateFriendPairings(int n)
{
  vector<int> friends(n);
  vector<bool> used(n, false);

  // Initialize the friends list
  for (int i = 0; i < n; ++i)
  {
    friends[i] = i + 1;
  }

  printPairingCombinations(friends, used, "");
}


int sumOfDigits(int n)
{
  if (n >= 0 && n <= 9)
    return n;
  return sumOfDigits(n / 10) + n % 10;
}
int printMaxOfArray(int *arr, int n, int idx)
{
  if (idx == n - 1)
    return arr[idx];
  return max(arr[idx], printMaxOfArray(arr, n, idx + 1));
}
int printSumofArrayValues(int *arr, int n, int idx)
{
  if (idx == n - 1)
  {
    return arr[idx];
  }
  return arr[idx] + printSumofArrayValues(arr, n, idx + 1);
}
string printNoConsectiveAs(string str, int idx)
{
  if (idx == str.size())
  {
    return "";
  }
  string curr = "";
  curr += str[idx];
  return ((str[idx] != 'a') ? curr : "") + printNoConsectiveAs(str,idx+1);
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  // cout << fact(5) << '\n';
  // cout << fib(5) << '\n';
  // printFirstNNaturalNumbers(5);
  // cout << friendsPairing(3) << endl;
  // pattern2(7,0);
  // int n;
  // cin >> n;
  // int *arr = new int[n];
  // for (int i = 0; i < n; i++)
  //   cin >> arr[i];
  // printSubset(arr, n, 0, "");
  // printNoConsecutiveOnes(3, 0, "");
  // int n = 3;
  // generateFriendPairings(n);
  // printPossiblePathsInMaze(3, 3, 0, 0, "");
  // printAllPossiblePathsOfDiceJumps(7, 0, "");
  // printLexico(1005, 0);
  // printStringPermutations("AAC", "");
  // cout << totalPaths << endl;
  // cout << sumOfDigits(653);

  // int n;
  // cin >> n;
  // int *arr = new int[n];
  // for (int i = 0; i < n; i++)
  //   cin >> arr[i];
  // // cout << printMaxOfArray(arr, n, 0);
  // cout << printSumofArrayValues(arr, n, 0);

  cout << printNoConsectiveAs("abcax",0);
  return 0;
}