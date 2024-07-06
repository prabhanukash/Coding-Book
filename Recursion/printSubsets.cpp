#include <bits/stdc++.h>
using namespace std;

void printSubsets(vector<int> & arr, int index, string osf){
    if(index==arr.size()){
        cout<<"["<<osf<<"]"<<endl;
        return ;
    }
    printSubsets(arr, index+1, osf+to_string(arr[index]));
    printSubsets(arr, index+1, osf);
}
int main()
{

    vector<int> arr = {1, 2, 3};
    printSubsets(arr, 0, "");
}