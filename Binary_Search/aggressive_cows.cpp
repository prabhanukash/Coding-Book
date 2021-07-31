// Problem Link -https://www.spoj.com/problems/AGGRCOW/
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
bool good(ll m, ll c, ll a[], ll n)
{
	sort(a, a + n);
	ll last_vis = a[0];
	ll cnt = 1;
	fr(i, 1, n)
	{
		if (a[i] - last_vis >= m)
		{
			last_vis = a[i];
			cnt++;
		}
		if (cnt == c)return true;
	}
	return false;
}
void solve()
{
	ll n, c;
	cin >> n >> c;
	ll a[n];
	ll mx = -1;
	fr(i, 0, n)cin >> a[i], mx = max(mx, a[i]);
	ll s = 0;
	//cout << mx << '\n';
	ll e = mx;
	ll ans = 0;
	//cout << s << ' ' << e << '\n';
	while (s <= e)
	{
		ll m = (s + e) >> 1;
		if (good(m, c, a, n))
		{

			ans = m;
			s = m + 1;
		}
		else e = m - 1;
	}
	cout << ans << '\n';
}

signed main()
{
	fast();
#ifndef ONLINE_JUDGE
	freopen ("inp.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif
	ll t = 1;
	cin >> t;
	fr(i, 0, t)
	{
		solve();
	}
}