#include <bits/stdc++.h>
using namespace std;

class Interval
{
public:
    int start, end;
    Interval() : start(0), end(0) {} // Default constructor
    Interval(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
};
bool cmp(Interval &a, Interval &b)
{
    return a.end < b.end;
}
int main()
{
    int n;
    cin >> n;
    vector<Interval> intervals(n);
    for (int i = 0; i < n; i++)
        cin >> intervals[i].start >> intervals[i].end;
    sort(intervals.begin(), intervals.end(), cmp);
    int lastEndTime = intervals[0].end;
    for (int i = 1; i < n; i++)
    {
        if (intervals[i].start < lastEndTime)
        {
            cout << "false\n";
            return 0;
        }
    }
    cout << "true\n";
    return 0;
}