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
ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0, 0, 1, -1};
bool vis[1000][1000];
queue<pii> q;
ll a[1000][1000];
bool f = false;
ll n, m;
bool issafe(ll i, ll j)
{
    return (i >= 0 and i < n and j >= 0 and j < m and vis[i][j] == false and a[i][j] == 1);
}
void dfs(ll x, ll y)
{
    vis[x][y] = true;
    q.push({x, y});
    fr(i, 0, 4)
    {
        ll X = dx[i] + x;
        ll Y = dy[i] = y;
        if (issafe(X, Y))
        {
            dfs(X, Y);
        }
    }
}
ll shortest_bridge()
{
    ll step = 0;
    while (q.empty() == false)
    {
        ll sz = q.size();
        while (sz != 0)
        {
            pii p = q.front();
            q.pop();
            fr(i, 0, 4)
            {
                ll X = dx[i] + p.ff;
                ll Y = dy[i] + p.ss;
                if (issafe(X, Y))
                {
                    if (a[X][Y] == 1)
                    {
                        f = true;
                        return step;
                    }
                    q.push({X, Y});
                    vis[X][Y] = true;
                }
            }
        }
        step++;
    } 
    return -1;
}
void solve()
{
    cin >> n >> m;
    fr(i, 0, n)
    {
        fr(j, 0, m)
        {
            cin >> a[i][j];
        }
    }
    fr(i, 0, n)
    {
        if (f)
            break;
        fr(j, 0, m)
        {
            if (a[i][j] == 1)
            {
                dfs(i, j);
                f = true;
                break;
            }
        }
    }
    cout << shortest_bridge() << '\n';
}

signed main()
{
    fast();
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll t = 1;
    //cin >> t;
    fr(i, 0, t)
    {
        solve();
    }
}