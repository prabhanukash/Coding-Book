#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

int largestSumAfterKNegations(vector<int> &nums, int k)
{
    // Create a min-heap from the array
    priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());

    // Perform k negations
    for (int i = 0; i < k; ++i)
    {
        // Extract the smallest element
        int smallest = minHeap.top();
        minHeap.pop();
        // Negate it
        smallest = -smallest;
        // Push it back to the heap
        minHeap.push(smallest);
    }

    // Calculate the total sum
    int sum = 0;
    while (!minHeap.empty())
    {
        sum += minHeap.top();
        minHeap.pop();
    }

    return sum;
}

int main()
{
    vector<int> nums1 = {4, 2, 3};
    int k1 = 1;
    cout << "Example 1: " << largestSumAfterKNegations(nums1, k1) << endl; // Output: 5

    vector<int> nums2 = {3, -1, 0, 2};
    int k2 = 3;
    cout << "Example 2: " << largestSumAfterKNegations(nums2, k2) << endl; // Output: 6

    vector<int> nums3 = {2, -3, -1, 5, -4};
    int k3 = 2;
    cout << "Example 3: " << largestSumAfterKNegations(nums3, k3) << endl; // Output: 13

    // TC: O(n log n + k log n).
    // SC: O(n)
    return 0;
}
