#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findPairsWithGivenDifference (vector<int> &arr, int k){
    int n = arr.size();
    vector<vector<int>> result;
    unordered_set<int> st(arr.begin(), arr.end());

    for(int y:arr){
        if(st.count(y+k)){
            result.push_back({y + k, y});
        }
    }
    return result;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n;i++)
        cin >> arr[i];
    vector<vector<int>> ans = findPairsWithGivenDifference(arr,k);
    for(vector<int> &v: ans){
        cout << v[0] << ' ' << v[1] << endl;
    }
    return 0;
}