#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
private:
    priority_queue<int> maxHeap;                            // Max heap to store the smaller half of the elements
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap to store the larger half of the elements

public:
    void addNum(int num)
    {
        if (maxHeap.empty() || num <= maxHeap.top())
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }

        // Balance the heaps
        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        if (maxHeap.size() == minHeap.size())
        {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else
        {
            return maxHeap.top();
        }
    }
};

int main()
{
    // Test case 1
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {5, 10, 15};
    MedianFinder mf1;
    for (int num : nums1)
    {
        mf1.addNum(num);
        cout << fixed << setprecision(1) << mf1.findMedian() << ", ";
    }
    cout << endl;

    // Test case 2
    cout << "Test Case 2:" << endl;
    vector<int> nums2 = {1, 2, 3, 4};
    MedianFinder mf2;
    for (int num : nums2)
    {
        mf2.addNum(num);
        cout << fixed << setprecision(1) << mf2.findMedian() << ", ";
    }
    cout << endl;

    return 0;
}
