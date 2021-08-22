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
	ll n, m;
	cin >> n >> m;
	ll a[n][m];
	fr(i, 0, n)
	{
		fr(j, 0, m)
		{
			cin >> a[i][j];
		}
	}
	ll rs = 0, re = m, cs = 0, ce = n;
	while (rs < re and cs < ce) {
		fr(i, cs, ce)
		{
			cout << a[rs][i] << ' ';
		}
		rs++;
		fr(i, rs, re)
		{
			cout << a[i][ce - 1] << ' ';
		}
		ce--;
		if (rs < re)
		{
			for (ll i = ce - 1; i >= cs; i--)cout << a[re - 1][i] << ' ';
			re--;
		}
		if (cs < ce)
		{
			for (ll i = re - 1; i >= rs; i--)cout << a[i][cs] << ' ';
			cs++;
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