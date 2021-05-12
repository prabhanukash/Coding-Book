#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
#define ff first
#define ss second
#define S size()
#define mod (ll)(1e9+7)
#define mset(a,k) memset(a,k,sizeof(a));
#define fr(i, x, y) for ( ll i = x; i < y;i++)
#define dr(i, x, y) for ( ll i = x; i >= y; i--)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define pqueue priority_queue<ll>
#define mapcl map<char,ll>
#define mapll map<ll,ll>
#define mapsl map<string,ll>
#define vi vector<ll>
#define vs vector<string>
#define psi pair<string,ll>
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define vii vector<pii>
using namespace std;
void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
//----------------------------------------START--------------------------------------------------------
const ll maxN = (ll)(1 * 1e5 + 5 );
struct edge
{
	ll u, v, w;
};
ll cost[maxN];
void solve()
{

	ll n, m;
	cin >> n >> m; // n nodes and m edges
	edge adj[m];
	fr(i, 0, m) // edge list
	{
		ll u, v, w;
		cin >> u >> v >> w;
		adj[i].u = u;
		adj[i].v = v;
		adj[i].w = w;
	}
	ll src ;
	cin >> src;// source from where we need to calculate SSSP
	cost[src] = 0;
	for (ll i = 0; i <= n - 1; i++) // relaxing for V-1 times
	{
		for (ll j = 0; j < m; j++)
		{

			if (cost[adj[j].u] < INT_MAX)
			{
				cost[adj[j].v] = min (cost[adj[j].v], cost[adj[j].u] + adj[j].w);// relaxing the edges
			}
		}
	}

	for (ll j = 0; j < m; j++)
	{

		if (cost[adj[j].u] < INT_MAX)
		{
			cout << "NEGATIVE CYCLE\n";
			return;
		}
	}
	fr(i, 0, n)
	{
		cout << cost[i] << '\n';
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