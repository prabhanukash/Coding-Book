#include<bits/stdc++.h>
using namespace std;

void printStringPermutations(string str, string osf){
	if(str.empty()){
		cout << osf << endl;
		return;
	}
	unordered_set<char> st;
	for (int i = 0; i < str.size();i++){
		char ch = str[i];
		if(st.count(ch)==0){
			st.insert(ch);
			string ros = str.substr(0, i) + str.substr(i + 1);
			printStringPermutations(ros, osf + ch);
		}
		
	}
}
int main(){
	printStringPermutations("ABC", "");
}