#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
#define ff first
#define ss second
#define S size()
#define inf 1e18
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
vi gen_digits(ll n)
{
	vi v;
	while (n)
	{
		if (n % 10)v.pb(n % 10);
		n /= 10;
	}
	return v;
}
void solve()
{
	ll n;
	cin >> n;
	if (n <= 9)
	{
		cout << 1 << '\n';
		return;
	}
	vi dp(n + 1, inf);
	fr(i, 1, 10)dp[i] = 1;
	fr(i, 10, n + 1)
	{
		vi d = gen_digits(i);
		for (auto j : d)
		{
			dp[i] = min(dp[i], 1 + dp[i - j]);
		}
	}
	cout << dp[n] << '\n';
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