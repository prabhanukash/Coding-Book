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
const ll LOGN = 25;
void solve()
{
	ll n, m;
	cin >> n >> m;
	ll a[n];
	ll prefix[n], suffix[n];
	prefix[0] = a[0];
	suffix[n - 1] = a[n - 1];
	fr(i, 0, n)cin >> a[i];
	fr(i, 1, n)
	{
		prefix[i] = __gcd(prefix[i - 1], a[i]);
	}
	for (ll i = n - 2; i >= 0; i--)
	{
		suffix[i] = __gcd(suffix[i + 1], a[i]);
	}
	while (m--)
	{
		ll l, r; cin >> l >> r;
		if (l == 0)cout << suffix[r + 1] << '\n';
		else if (r == n - 1)cout << prefix[l - 1] << '\n';
		else cout << __gcd(prefix[l - 1], suffix[r + 1]);
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
		solve();
	}
}