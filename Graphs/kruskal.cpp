#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
#define ff first
#define ss second
#define S size()
#define mod (ll)(1e9 + 7)
#define mset(a, k) memset(a, k, sizeof(a))
#define fr(i, x, y) for (ll i = x; i < y; i++)
#define dr(i, x, y) for (ll i = x; i >= y; i--)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define mapcl map<char, ll>
#define mapll map<ll, ll>
#define mapsl map<string, ll>
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
void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
//----------------------------------------FUNCTIONS-------------------------------------
const ll N = (ll)(1 * 1e6 + 5);
class union_find
{
public:
	ll *pr;
	ll *sz;

	union_find(ll n)
	{
		pr = new ll[n + 1];
		sz = new ll[n + 1];

		for (ll i = 1; i <= n; ++i)
			pr[i] = i, sz[i] = 1;
	}

	ll root(ll i)
	{
		if (pr[i] == i)
			return i;

		return pr[i] = root(pr[pr[i]]);
	}

	ll find(ll i, ll j)
	{
		return (root(i) == root(j));
	}

	ll un(ll i, ll j)
	{
		ll u = root(i);
		ll v = root(j);

		if (u == v)
			return 0;

		if (sz[u] < sz[v])
			swap(u, v);

		pr[v] = u;
		sz[u] += sz[v];

		return 1;
	}
}; //default indexing is 1-based


void solve()
{
	ll n, m;
	cin >> n >> m;
	vector<vi> adj(m);

	fr(i, 0, m)
	{
		ll u, v, w; cin >> u >> v >> w;
		adj[i] = {w, u, v};
	}

	sort(adj.begin(), adj.end());
	set<vi> mst;
	int min_cost = 0;

	union_find dsu(n); // everyone is in a different component of its own

	for (auto &e : adj)
	{
		if (mst.size() == n - 1) // it should contain V-1 vertices in the tree
			break;

		ll u = e[1], v = e[2];

		if (!dsu.find(u, v))
		{
			mst.insert(e);
			dsu.un(u, v);
			min_cost += e[0];
		}
	}

	cout << min_cost << '\n';

	for (auto e : mst)
	{
		cout << e[1] << ' ' << e[2] << '\n';
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