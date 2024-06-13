#include <bits/stdc++.h>
using namespace std;

// Class to represent an interval
class Interval
{
public:
    int start, end;
    Interval() : start(0), end(0) {}
    Interval(int start, int end) : start(start), end(end) {}
};

// Comparison function to sort intervals by their end times
bool cmp(const Interval &a, const Interval &b)
{
    return a.end < b.end;
}

// Function to calculate the minimum number of meeting rooms required
int minMeetingRooms(vector<Interval> &intervals)
{
    if (intervals.empty())
        return 0;

    // Sort the intervals by end times
    sort(intervals.begin(), intervals.end(), cmp);

    int cnt = 1;                        // Count of non-overlapping intervals
    int lastEndTime = intervals[0].end; // End time of the last added interval

    // Iterate over the intervals
    for (int i = 1; i < intervals.size(); i++)
    {
        // If the current interval starts after or when the last one ends, it does not overlap
        if (intervals[i].start >= lastEndTime)
        {
            cnt++;
            lastEndTime = intervals[i].end; // Update the end time
        }
    }

    // The minimum number of rooms required is the total intervals minus the count of non-overlapping intervals
    return intervals.size() - cnt;
}

int main()
{
    int n; // Number of intervals
    cin >> n;
    vector<Interval> intervals(n); // Vector to store the intervals

    // Read the intervals
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        intervals[i] = Interval(start, end);
    }

    // Calculate and print the minimum number of meeting rooms required
    cout << minMeetingRooms(intervals) << endl;

    return 0;
}
