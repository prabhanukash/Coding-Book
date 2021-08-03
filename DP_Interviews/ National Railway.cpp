// Problem Link -https://atcoder.jp/contests/abc210/tasks/abc210_d
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
	ll n, m, c;
	cin >> n >> m >> c;
	ll a[n][m];
	fr(i, 0, n)
	{
		fr(j, 0, m)cin >> a[i][j];
	}
	ll pref[n][m], suff[n][m];
	fr(i, 0, n)
	{
		fr(j, 0, m)
		{
			pref[i][j] = a[i][j] - c * (i + j);
			if (i)
			{
				pref[i][j] = min(pref[i][j], pref[i - 1][j]);
			}
			if (j)
			{
				pref[i][j] = min(pref[i][j], pref[i][j - 1]);
			}
		}
	}

	fr(i, 0, n)
	{
		for (ll j = m - 1; j >= 0; j--)
		{
			suff[i][j] = a[i][j] + c * (j - i);
			if (i)
			{
				suff[i][j] = min(suff[i][j], suff[i - 1][j]);
			}
			if (j + 1 < m)
			{
				suff[i][j] = min(suff[i][j], suff[i][j + 1]);
			}
		}
	}
	ll ans = inf;
	fr(i, 0, n)
	{
		fr(j, 0, m)
		{
			ll pref_val = inf;
			if (i)
			{
				pref_val = min(pref_val, pref[i - 1][j]);
			}
			if (j)
			{
				pref_val = min(pref_val, pref[i][j - 1]);
			}
			ans = min(pref_val + a[i][j] + c * (i + j), ans);

			ll suff_val = inf;
			if (i)
			{
				suff_val = min(suff_val, suff[i - 1][j]);
			}
			if (j + 1 < m)
			{
				suff_val = min(suff_val, suff[i][j + 1]);
			}
			ans = min(suff_val + a[i][j] + c * ( i - j), ans);
		}
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
//	cin >> t;
	fr(i, 0, t)
	{
		solve();
	}
}