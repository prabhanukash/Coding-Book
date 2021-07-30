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
void mergeHelper(vi &a, ll s, ll m, ll e)
{
	ll n = e - s + 1;
	cout << n << '\n';
	vi tmp(n, 0);
	ll i = s;
	ll j = m + 1;
	ll k = 0;
	while (i <= m and j <= e)
	{
		if (a[i] <= a[j])
		{
			tmp[k] = a[i++];
		}
		else
		{
			tmp[k] = a[j++];
		}
		k++;
	}
	while (i <= m)
	{
		tmp[k] = a[i];
		i++;
		k++;
	}
	while (j <= e)
	{
		tmp[k] = a[j];
		k++; j++;
	}
	fr(i, s, e + 1)a[i] = tmp[i - s];
}
void mergeSort(vi &a, ll s, ll e)
{
	if (s < e)
	{
		ll m = (s + e) / 2;
		mergeSort(a, s, m);
		mergeSort(a, m + 1, e);
		mergeHelper(a, s, m, e);
	}
}
void solve()
{
	ll n;
	cin >> n;
	vi a(n);
	fr(i, 0, n)cin >> a[i];
	mergeSort(a, 0, n - 1);
	fr(i, 0, n)cout << a[i] << ' ';
	cout << '\n';
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