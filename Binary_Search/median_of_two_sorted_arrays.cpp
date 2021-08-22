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
double find_median(ll a[], ll b[], ll n, ll m)
{
	ll s = 0;
	ll e = n;
	while (s <= e)
	{
		ll par_x = (s + e) >> 1;
		ll par_y = (n + m + 1) >> 1 - (par_x);
		ll left_max_x = (par_x == 0) ? -inf : a[par_x - 1];
		ll left_max_y = (par_y == 0) ? -inf : b[par_y - 1];
		ll right_min_x = (par_x == n) ? inf : a[par_x];
		ll right_min_y = (par_y == m) ? inf : a[par_y];
		if (left_max_x <= right_min_y and left_max_y <= right_min_x)
		{
			if ((n + m) % 2)return max(left_max_y, left_max_x);
			else return (max(left_max_y, left_max_x) + min(right_min_x, right_min_y)) / 2;
		}
		if (left_max_x > right_min_y)e = par_x - 1;
		else s = par_x + 1;
	}
}
void solve()
{
	ll n, m;
	cin >> n >> m;
	ll a[n], b[m];
	fr(i, 0, n)cin >> a[i];
	fr(i, 0, m)cin >> b[i];
	if (n > m)cout << find_median(b, a, m, n) << '\n';
	else cout << find_median(a, b, n, m) << '\n';
}

signed main()
{
	fast();
#ifndef ONLINE_JUDGE
	freopen ("inp.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif
	ll t = 1;
//	cin >> t;
	fr(i, 0, t)
	{
		solve();
	}
}