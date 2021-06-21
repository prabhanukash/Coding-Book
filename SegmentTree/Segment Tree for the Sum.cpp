// Problem Link -https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A
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

struct segtree
{
	vi sums;
	ll sz;
	void init(ll n)
	{
		sz = 1;
		while (sz < n)
			sz *= 2;
		sums.assign(2 * sz, 0LL);
	}
	void build(vi &a, ll x, ll lx, ll rx)
	{
		if (rx - lx == 1)
		{
			if (lx < (ll)a.S)
				sums[x] = a[lx];
			return;
		}
		ll m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}
	void build(vi &a)
	{
		build(a, 0, 0, sz);
	}
	ll sum(ll l, ll r, ll x, ll lx, ll rx)
	{
		if (l >= rx || lx >= r)
			return 0;
		if (lx >= l && rx <= r)
			return sums[x];
		ll m = (lx + rx) / 2;
		ll s1 = sum(l, r, 2 * x + 1, lx, m);
		ll s2 = sum(l, r, 2 * x + 2, m, rx);
		return s1 + s2;
	}
	ll sum(ll l, ll r)
	{
		return sum(l, r, 0, 0, sz);
	}
	void set(ll i, ll v, ll x, ll lx, ll rx)
	{
		if (rx - lx == 1)
		{
			sums[x] = v;
			return;
		}
		ll m = (lx + rx) / 2;
		if (i < m)
		{
			set(i, v, 2 * x + 1, lx, m);
		}
		else
		{
			set(i, v, 2 * x + 2, m, rx);
		}
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}
	void set(ll i, ll v)
	{
		set(i, v, 0, 0, sz);
	}
};

void solve()
{
	ll n, m;
	cin >> n >> m;
	vi a(n);
	segtree st;
	st.init(n);
	fr(i, 0, n) cin >> a[i];
	st.build(a);
	while (m--)
	{
		ll ty;
		cin >> ty;
		if (ty == 1)
		{
			ll i, v;
			cin >> i >> v;
			st.set(i, v);
		}
		else
		{
			ll l, r;
			cin >> l >> r;
			cout << st.sum(l, r) << '\n';
		}
	}
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