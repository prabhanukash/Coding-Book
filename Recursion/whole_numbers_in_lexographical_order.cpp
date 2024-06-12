#include<bits/stdc++.h>
using namespace std;
void printLexico(int n, int i)
{
	if (n < i)
		return;
	cout << i << endl;
	for (int j = (i == 0) ? 1 : 0; j <= 9; j++)
	{
		printLexico(n, 10 * i + j);
	}
}
int main(){
	printLexico(13, 0);
}