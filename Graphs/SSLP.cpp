#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
#define ff first
#define INF 1e18
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
stack<ll> s;
vi tin, tout, vis, dist;
ll tmr;
void topo_sort(ll u)
{
	vis[u] = 1;
	for (auto it : adj[u])
	{
		ll v = it.ff;
		if (vis[v] == 0)topo_sort(v);
	}
	s.push(u);
}
void findLongestDistances(ll start, ll n)
{
	tin.resize(n, -1);
	tout.resize(n, -1);
	vis.resize(n, 0);
	dist.resize(n, -INF);
	fr(i, 0, n)
	{
		if (!vis[i])topo_sort(i);
	}
	dist[start] = 0;
	while (s.empty() == false) {
		ll u = s.top();
		s.pop();

		if (dist[u] != -INF) {
			for (auto it : adj[u]) {

				if (dist[it.ff] < dist[u] + it.ss)
					dist[it.ff] = dist[u] + it.ss;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << "dist(" << start << ", " << i << ") = " << setw(2) << dist[i];
		cout << endl;
	}
}
void solve()
{
	ll n, m;
	cin >> n >> m;
	fr(i, 0, m)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({v, w});
	}
	ll start;
	cin >> start;
	findLongestDistances(start, n);
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
/*
8 11
0 6 2
1 2 -4
1 4 1
1 6 8
3 0 3
3 4 5
5 1 2
7 0 6
7 1 -1
7 3 4
7 5 -4
7
*/