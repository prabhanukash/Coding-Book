#include <bits/stdc++.h>
using namespace std;

// Function to check if the given value 'val' satisfies the condition for 'c'
bool good(double val, double c)
{
    double left = val * val + sqrt(val);
    return left <= c;
}

int main()
{
    double c;
    cin >> c;

    // Edge case handling for negative and zero input
    if (c < 0)
    {
        cerr << "The value of 'c' should be non-negative." << endl;
        return 1;
    }

    // Initialize binary search boundaries
    double l = 0;
    double r = 1e10;

    // Binary search to find the appropriate value of 'val'
    for (int t = 0; t < 100; t++)
    {
        double m = (l + r) / 2;
        if (good(m, c))
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }

    // Set precision and output the result
    cout << fixed << setprecision(20) << l << endl;

    return 0;
}
