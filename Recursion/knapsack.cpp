#include <bits/stdc++.h>
using namespace std;

int f(int *c, int *w, int n, int W)
{
    if (n == 0 or W == 0)
        return 0;
    if(w[n-1]>W)
        return f(c, w, n - 1, W); // prune
    int sp1 = c[n - 1] + f(c, w, n - 1, W - w[n - 1]); // include
    int sp2 = f(c, w, n - 1, W); // not include
    return max(sp1, sp2);
}
int main()
{
    int n, W;
    cin >> n >> W;
    int c[n], w[n];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
        cin >> w[i];
    cout << f(c, w, n, W) << endl;
    return 0;
}