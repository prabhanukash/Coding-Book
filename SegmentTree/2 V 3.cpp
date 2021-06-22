// Problem Link -https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/2-vs-3/
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
const ll N = (ll)(1 * 1e5 + 5);
ll p[N];
void fastpow()
{
	p[0] = 1;
	for (ll i = 1; i <= N; ++i)
		p[i] = (p[i - 1] * 2) % 3;
}

struct segtree
{

	vector<ll> sums;
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
		sums[x] = ((p[rx - m ] * sums[2 * x + 1]) + sums[2 * x + 2]) % 3;
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
			return sums[x] * p[r - rx ];
		ll m = (lx + rx) / 2;
		ll s1 = sum(l, r, 2 * x + 1, lx, m);
		ll s2 = sum(l, r, 2 * x + 2, m, rx);
		return (s1 + s2) % 3;
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
		sums[x] = ((p[rx - m] * sums[2 * x + 1]) + sums[2 * x + 2]) % 3;
	}
	void set(ll i, ll v)
	{
		set(i, v, 0, 0, sz);
	}
};
void solve()
{

	ll n;
	cin >> n;
	string s;
	cin >> s;
	vi a(n);
	fr(i, 0, n)
	{
		a[i] = s[i] - '0';
	}
	segtree st;
	st.init(n);
	st.build(a);

	ll m;
	cin >> m;
	while (m--)
	{

		ll op;
		cin >> op;
		if (op == 1)
		{
			ll i;
			cin >> i;
			//i--;
			if (s[i] == '0')
			{
				s[i] = '1';
				a[i] = 1 - a[i];
				st.set(i, a[i]);
			}
		}
		else
		{
			ll l, r;
			cin >> l >> r;
			//	l--;
			cout << st.sum(l, r + 1) << '\n';
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
	fastpow();
	fr(i, 0, t)
	{
		solve();
	}
}