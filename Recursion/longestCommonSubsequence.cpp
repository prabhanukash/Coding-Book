#include<bits/stdc++.h>
using namespace std;
int lcs(string s1, string s2, int n, int m){
    if(n==0 or m==0)
        return 0;
    if(s1[n-1]==s2[m-1])
        return 1 + lcs(s1, s2, n - 1, m - 1);
    return max(lcs(s1, s2, n - 1, m), lcs(s1, s2, n, m - 1));
}
int main(){
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    cout << lcs(s1,s2,s1.size(),s2.size());
    return 0;
}