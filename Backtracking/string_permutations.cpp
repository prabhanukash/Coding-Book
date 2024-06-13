#include<bits/stdc++.h>
using namespace std;
void printStringPermutations(string str, int idx){
    if(idx==str.size()-1){
        cout << str << endl;
        return;
    }
    for (int i = idx; i < str.size();i++){
        swap(str[i], str[idx]);
        printStringPermutations(str, idx + 1);
        swap(str[i], str[idx]);
    }
}
int main(){
    printStringPermutations("ABC", 0);
    return 0;
}