#include <bits/stdc++.h>
using namespace std;
struct segtree
{
private:
    int size;
    vector<int> minis;

    void build(vector<int> &arr, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < arr.size())
            {
                minis[x] = arr[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(arr, 2 * x + 1, lx, m);
        build(arr, 2 * x + 2, m, rx);
        minis[x] = min(minis[2 * x + 1], minis[2 * x + 2]);
    }
    long long mini(int l, int r, int x, int lx, int rx)
    {
        if (l >= rx or lx >= r)
            return INT_MAX;
        if (lx >= l and rx <= r)
            return minis[x];
        int m = (lx + rx) >> 1;
        int s1 = mini(l, r, 2 * x + 1, lx, m);
        int s2 = mini(l, r, 2 * x + 2, m, rx);
        return min(s1, s2);
    }
    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            minis[x] = v;
            return;
        }
        int m = (lx + rx) >> 1;
        if (i < m)
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);
        minis[x] = min(minis[2 * x + 1], minis[2 * x + 2]);
    }

public:
    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        minis.assign(2 * size, 0);
    }

    void build(vector<int> &arr)
    {
        build(arr, 0, 0, size);
    }

    long long mini(int l, int r)
    {
        return mini(l, r, 0, 0, size);
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }
};
int main()
{

    int n, m;
    cin >> n >> m;

    segtree st;
    st.init(n);

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    st.build(arr);

    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << st.mini(l, r) << endl;
        }
    }
    return 0;
}