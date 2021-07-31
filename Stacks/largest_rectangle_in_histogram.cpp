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
vi NSE(vi &v)
{
	ll n = v.S;
	ll a[n];
	fr(i, 0, n)a[i] = -v[i];
	vi nse(n, -1);
	stack<ll> s;
	s.push(a[n - 1]);
	for (ll i = n - 2; i >= 0; i--)
	{
		while (s.empty() == false and a[i] >= s.top())s.pop();
		if (s.empty() == false)nse[i] = -s.top();
		else nse[i] = -1;
		s.push(a[i]);
	}
	return nse;
}
vi PSE(vi &v)
{
	ll n = v.S;
	ll a[n];
	fr(i, 0, n)a[i] = -v[i];
	reverse(a, a + n);
	vi pse(n, -1);
	stack<ll> s;
	s.push(a[n - 1]);
	for (ll i = n - 2; i >= 0; i--)
	{
		while (s.empty() == false and a[i] >= s.top())s.pop();
		if (s.empty() == false)pse[i] = -s.top();
		else pse[i] = -1;
		s.push(a[i]);
	}
	reverse(all(pse));
	return pse;
}
void solve()
{
	ll n;
	cin >> n;
	vi a(n);
	fr(i, 0, n)cin >> a[i];
	vi nse = NSE(a);
	vi pse = PSE(a);
	for (auto i : nse)cout << i << ' ';
	cout << '\n';
	for (auto i : pse)cout << i << ' ';
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