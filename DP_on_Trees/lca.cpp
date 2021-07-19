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
const ll N = (ll)(1 * 1e5 + 5);
const ll LOGN = 22;
vi adj[N];
ll lev[N];
ll par[N][LOGN];
// Dynamic Programming Sparse Matrix Approach
// populating 2^i par for each node
// Time complexity : O(nlogn)
void precomputeSparseMatrix(ll n)
{
	for (ll i = 1; i < LOGN; i++)
	{
		for (ll node = 1; node <= n; node++)
		{
			if (par[node][i - 1] != -1)
			{
				par[node][i] = par[par[node][i - 1]][i - 1];

			}
		}
	}
}
// Returning the LCA of u and v
// Time complexity : O(log n)
ll lca(ll u, ll v)
{
	if (lev[v] < lev[u])
		swap(u, v);

	ll diff = lev[v] - lev[u];
	for (ll i = 0; i < LOGN; i++)
	{
		if ((diff >> i) & 1)
		{
			v = par[v][i];
		}
	}
	// now both nodes are in the same level
	if (u == v) return u;
	for (ll i = LOGN - 1; i >= 0; i--)
	{
		if (par[u][i] != par[v][i])
		{
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}
// pre-compute the lev for each node and their
// first par(2^0th par)
// time complexity : O(n)
void dfs(ll u, ll p)
{
	lev[u] = lev[p] + 1;
	par[u][0] = p;
	for (auto v : adj[u])
	{
		if (v == p)continue;
		dfs(v, u);
	}
}
void solve()
{
	ll n, m, u, v;
	cin >> n >> m;
	fr(i, 1, n)
	{
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, 0);
	for (ll i = 0; i < LOGN; i++)
	{
		par[0][i] = 0;
	}
	precomputeSparseMatrix(n);
	while (m--)
	{
		cin >> u >> v;
		cout << lca(u, v) << '\n';
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
	cin >> t;
	fr(i, 0, t)
	{
		memset(par, -1, sizeof(par));
		solve();
	}
}




