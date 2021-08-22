// Problem Link -
/* By Bhanu Prakash */
#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
#define ll long long int
#define ff first
#define ss second
#define S size()
#define mod (ll)(1e9 + 7)
#define inf 1e18
#define fr(i, x, y) for (ll i = x; i < y; i++)
#define dr(i, x, y) for (ll i = x; i >= y; i--)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define mapcl map<char, ll>
#define mapll map<ll, ll>
#define vi vector<ll>
#define vs vector<string>
#define vb vector<bool>
#define psi pair<string, ll>
#define pii pair<ll, ll>
#define piii pair<ll, pii>
#define vii vector<pii>
#define vvi vector<vi>
#define vvii vector<vii>
using namespace std;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
//----------------------------------------FUNCTIONS-------------------------------------
const ll N = (ll)(1 * 1e6 + 5);

void solve()
{

    ll n;
    priority_queue<ll, vi, greater<ll>> larger_min_heap; //numbers greater than median in sorted array
    priority_queue<ll> smaller_max_heap;                 // numbers smaller than median in sorted array
    ll cnt = 0;
    while (true)
    {
        cin >> n;
        if (n == 0)
            return;
        if (n == -1)
        {
            // cout << "==> " << cnt << '\n';
            // cout << smaller_max_heap.S << ' ' << larger_min_heap.S << '\n';
            // cout << smaller_max_heap.top() << ' ' << larger_min_heap.top() << '\n';
            if (larger_min_heap.S == smaller_max_heap.S)
            {
                //cout << (larger_min_heap.top() + smaller_max_heap.top()) / 2 << '\n';
                cout << smaller_max_heap.top() << '\n';
                smaller_max_heap.pop();
            }
            else if (larger_min_heap.S - 1 == smaller_max_heap.S)
            {
                cout << larger_min_heap.top() << '\n';
                larger_min_heap.pop();
            }
            else if (larger_min_heap.S == smaller_max_heap.S - 1)
            {
                cout << smaller_max_heap.top() << '\n';
                smaller_max_heap.pop();
            }
        }
        else
        {
            if (larger_min_heap.S == 0 and smaller_max_heap.S == 0)
                larger_min_heap.push(n);
            else if (n >= larger_min_heap.top())
                larger_min_heap.push(n);
            else if (n < larger_min_heap.top())
                smaller_max_heap.push(n);
            if (larger_min_heap.S > smaller_max_heap.S and (larger_min_heap.S - smaller_max_heap.S) >= 2)
            {
                ll x = larger_min_heap.top();
                larger_min_heap.pop();
                smaller_max_heap.push(x);
            }
            else if (larger_min_heap.S < smaller_max_heap.S and (smaller_max_heap.S - larger_min_heap.S) >= 2)
            {
                ll x = smaller_max_heap.top();
                smaller_max_heap.pop();
                larger_min_heap.push(x);
            }
        }
    }
}

signed main()
{
    fast();
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll t = 1;
    cin >> t;
    fr(i, 0, t)
    {
        solve();
    }
}