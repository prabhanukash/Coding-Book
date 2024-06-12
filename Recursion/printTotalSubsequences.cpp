#include <bits/stdc++.h>
using namespace std;
void printTotalSubsequences(string str, int idx, string osf, vector<string> &res) {

    if(idx==str.size()){
        res.push_back(osf);
        return;
    }
    printTotalSubsequences(str, idx + 1, osf + str[idx],res);
    printTotalSubsequences(str, idx + 1, osf,res);
}
int main()
{
    vector<string> ans;
    printTotalSubsequences("abc", 0, "",ans);
    for (string str : ans)
        cout << str << endl;
}