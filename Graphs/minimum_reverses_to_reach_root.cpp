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
#define inf 1e10
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
vii adj[N];
ll n, s;
ll bfs_0_1(ll s)
{
	vi d(1e4 + 5, INT_MAX);
	deque<ll> q;
	q.push_front(s);
	d[s] = 0;
	while (q.empty() == false)
	{
		ll u = q.front();
		q.pop_front();
		for (auto it : adj[u])
		{
			ll v = it.ff;
			ll w = it.ss;
			if (d[v] > d[u] + w)d[v] = d[u] + w;
			if (w == 0)q.push_front(v);
			else q.push_back(v);
		}
	}
	ll ans = 0;
	fr(i, 1, n + 1)ans += d[i];
	return ans;
}

void solve()
{
	cin >> n >> s;
	fr(i, 1, n)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].pb({v, 0});
		adj[v].pb({u, 1});
	}
	ll ans = bfs_0_1(s);
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