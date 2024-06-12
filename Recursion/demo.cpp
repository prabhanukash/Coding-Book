#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if (n <= 1)
        return 1;
    int sp = fact(n - 1);
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
void printArray(int arr[], int n, int idx)
{
    if (idx == n)
        return;
    cout << arr[idx] << ' ';
    return printArray(arr, n, idx + 1);
}
int printMaxOfArray(int *arr, int n, int idx)
{
    if (idx == n - 1)
        return arr[idx];
    return max(arr[idx], printMaxOfArray(arr, n, idx + 1));
}
int printSumOfValuesOfArray(int *arr, int n, int idx)
{
    if (idx == n - 1)
        return arr[idx];
    int sp = printSumOfValuesOfArray(arr, n, idx + 1);
    return arr[idx] + sp;
}
string removeAllOccurencesOfA(string str, int idx)
{
    if (idx == str.size())
        return "";
    if (str[idx] != 'a')
    {
        return str[idx] + removeAllOccurencesOfA(str, idx + 1);
    }
    else
    {
        return removeAllOccurencesOfA(str, idx + 1);
    }
}
void print(int n)
{
    if (n < 1)
        return;
    print(n - 1);
    cout << n << ' ';
}
void printKMultiplesOfN(int n, int k)
{
    if (k == 0)
        return;
    printKMultiplesOfN(n, k - 1);
    cout << n * k << ' ';
}
int sum(int n)
{
    if (n == 0)
        return 0;
    return sum(n - 1) + ((n % 2 == 0) ? (-n) : (n));
}
int pow(int a, int b){
    if(b==0)
        return 1;
    if(b==1)
        return a;
    int sp = pow(a, b / 2);
    if(b%2)
        return a * sp * sp;
        else
            return sp * sp;
}
int gcd(int a, int b)
{
    if (b > a)
        return gcd(b, a);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int isArmstrong(int n, int d){
    if(n==0)
        return 0;
    return isArmstrong(n / 10, d) + pow(n % 10, d);
}
int main()
{
    // cout << fact(5);
    // cout << fib(6); // 0 1 1 2 3 5 8
    // int arr[] = {1, 2, 3, 4, 15};
    // cout << printSumOfValuesOfArray(arr, 5, 0);
    // cout << removeAllOccurencesOfA("abcax", 0);
    // printKMultiplesOfN(12, 5);
    // cout << pow(5,3);
    if(isArmstrong(111, 3) == 153){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}