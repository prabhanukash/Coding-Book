#include <bits/stdc++.h>
using namespace std;
int recursivePower(int a, int b)
{
  if (b == 0)
    return 1;
  if (b == 1)
    return a;

  int sp = recursivePower(a, b / 2);
  if (b % 2 == 0)
  {
    return sp * sp;
  }
  else
  {
    return a * sp * sp;
  }
}
int main()
{
  int a = 3, b = 2;
  cout << recursivePower(4, 2);
  return 0;
}