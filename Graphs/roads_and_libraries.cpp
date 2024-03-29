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
vi adj[N];
ll nr;
bool vis[N];
ll lev[N];
void solve()
{
	ll q;
	cin >> q;
	while (q--)
	{
		ll n, m;
		cin >> n >> m;
		fr(i, 1, n + 1)
		{
			vis[i] = false;
			lev[i] = 0;
			adj[i].clear();
		}
		fr(i, 0, m)
		{
			ll u, v;
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		ll s;
		cin >> s;
		vi lev(n + 1, -1);
		queue<ll> q;
		lev[s] = 0;
		q.push(s);

		while (!q.empty()) {
			ll u = q.front();
			q.pop();
			for (auto v : adj[u]) {
				if (lev[v] == -1) {
					lev[v] = lev[u] + 6;
					q.push(v);
				}
			}
		}

		for (ll i = 1; i < lev.size(); i++) {
			if (lev[i] != 0)
				cout << lev[i] << " ";
		}
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