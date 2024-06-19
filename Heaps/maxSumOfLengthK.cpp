#include <bits/stdc++.h>
using namespace std;

vector<int> maxSumOfLengthK(vector<int> &a, int k)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {element,idx}

    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        pq.push({a[i], i});
        if (pq.size() > k)
            pq.pop();
        }

    vector<pair<int, int>> sub;
    while (pq.size() > 0)
    {
        int val = pq.top().first, idx = pq.top().second;
        pq.pop();

        sub.push_back({idx, val}); // storing index to print in correct order
    }
    sort(sub.begin(), sub.end());

    vector<int> ans;
    for (int i = 0; i < k; i++)
        ans.push_back(sub[i].second);

    return ans;
}
int main()
{
    // Test cases
   vector<int> nums1 = {2, 1, 3, 3};
   vector<int> result1 = maxSumOfLengthK(nums1, 2);
   cout << "Test Case 1: ";
    for (int num : result1)
    {
       cout << num << " ";
    }
   cout <<endl;

   vector<int> nums2 = {-1, -2, 3, 4};
   vector<int> result2 = maxSumOfLengthK(nums2, 3);
   cout << "Test Case 2: ";
    for (int num : result2)
    {
       cout << num << " ";
    }
   cout <<endl;

   vector<int> nums3 = {3, 4, 3, 3};
   vector<int> result3 = maxSumOfLengthK(nums3, 2);
   cout << "Test Case 3: ";
    for (int num : result3)
    {
       cout << num << " ";
    }
   cout <<endl;

    return 0;
}
