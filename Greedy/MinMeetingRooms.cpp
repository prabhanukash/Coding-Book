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

// Comparison function to sort intervals by their start times
bool cmp(const Interval &a, const Interval &b)
{
    return a.start < b.start;
}

// Function to calculate the minimum number of meeting rooms required
int minMeetingRooms(vector<Interval> &intervals)
{
    if (intervals.empty())
        return 0;

    // Sort the intervals by start times
    sort(intervals.begin(), intervals.end(), cmp);

    // Priority queue to track the end times of ongoing meetings (min-heap behavior using negative values)
    priority_queue<int> endTimes;

    // Add the end time of the first interval (using negative to simulate min-heap)
    endTimes.push(-intervals[0].end);

    // Iterate over the intervals starting from the second one
    for (int i = 1; i < intervals.size(); i++)
    {
        // If the current meeting starts after the earliest ending meeting, we can reuse the room
        if (intervals[i].start >= -endTimes.top())
        {
            endTimes.pop(); // Remove the meeting that has finished
        }
        // Add the current meeting's end time
        endTimes.push(-intervals[i].end);
    }

    // The size of the priority queue represents the minimum number of rooms required
    return endTimes.size();
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
