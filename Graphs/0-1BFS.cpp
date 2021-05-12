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
vii adj[N];
void solve()
{
	ll n, m;// n nodes and m edges
	cin >> n >> m;
	fr(i, 0, m)// information of the graph with 0-1 weights
	{
		ll u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({v, w});

	}
	ll src;
	cin >> src;
	vi dist(n + 1, INT_MAX);
	deque<ll> q; // we use double ended queue for the sake of relaxation
	dist[src] = 0;
	q.push_front(src);
	while (!q.empty())
	{
		ll x = q.front();
		q.pop_front();
		for (auto it : adj[x])
		{
			if (dist[it.ff] > dist[x] + it.ss)dist[it.ff] = dist[x] + it.ss;
			if (it.ss == 0)q.push_front(it.ff);
			else q.push_back(it.ff);
		}
	}
	fr(i, 0, n)
	{
		cout << "dist(" << src << ", " << i << ") = " << setw(2) << dist[i];
		cout << endl;
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