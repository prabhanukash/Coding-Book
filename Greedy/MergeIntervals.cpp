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
bool cmp(Interval &a, Interval &b)
{
    return a.start < b.start;
}
vector<Interval> mergeIntervals(vector<Interval> &intervals)
{
    vector<Interval> mergedIntervals;
    sort(intervals.begin(), intervals.end(), cmp);
    Interval tempInterval = intervals[0];

    for (Interval it : intervals)
    {
        if (it.start <= tempInterval.end)
        {
            tempInterval.end = max(it.end, tempInterval.end);
        }
        else
        {
            mergedIntervals.push_back(tempInterval);
            tempInterval = it;
        }
    }
    mergedIntervals.push_back(tempInterval);
    return mergedIntervals;
}
int main()
{
    int n;
    cin >> n;
    vector<Interval> intervals(n);
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        intervals[i] = Interval(start, end);
    }
    vector<Interval> ans = mergeIntervals(intervals);
    for (Interval &i : ans)
    {
        cout << i.start << ' ' << i.end << endl;
    }
}