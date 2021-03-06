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

void solve()
{
	ll n, m;
	cin >> n >> m;
	fr(i, 0, m)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}
	ll ans = 0;

	vi minEdge(n + 1, inf), inc(n + 1);

	set<pii> s; //{min_w,u}
	s.insert({0, 1});
	minEdge[1] = 0;

	for (ll i = 1; i <= n; ++i)
	{
		if (s.empty())
			return -1;

		auto it = s.begin();
		ll u = it->second;

		s.erase(it);

		inc[u] = 1;
		ans += minEdge[u];

		for (auto &e : adj[u])
		{
			ll v = e.first, w = e.second;

			if (inc[v])
				continue;

			if (w < minEdge[v])
			{
				s.erase({minEdge[v], v});
				minEdge[v] = w;
				s.insert({minEdge[v], v});
			}
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