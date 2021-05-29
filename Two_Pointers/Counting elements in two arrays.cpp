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
	vii a;
	vi b(m);
	fr(i, 0, n)
	{
		ll x;
		cin >> x;
		a.pb({x, i});
	}
	fr(i, 0, m)cin >> b[i];
	sort(all(a));
	sort(all(b));
	vi ans(n);
	ll j = 0, cnt = 0;
	for (ll i = 0; i < n; i++)
	{
		for (; j < m; j++)
		{
			if (a[i].ff >= b[j])
			{
				cnt++;
			}
			else break;

		}
		ans[a[i].ss] = cnt;
	}
	fr(i, 0, n)cout << ans[i] << ' ';
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