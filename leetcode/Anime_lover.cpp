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
const ll N = (ll)(1 * 1e7 + 5);
const ll LOGN = 25;
bool prime[N ];
void Sieve()
{

	memset(prime, true, sizeof(prime));
	prime[1] = false;
	for (ll  p = 2; p * p <= N; p++)
	{

		if (prime[p] == true)
		{
			for (ll i = p * p; i <= N; i += p)
				prime[i] = false;
		}
	}
}
void solve()
{
	ll n; cin >> n;
	ll ans = 0;
	fr(i, 1, n + 1)if (prime[i])ans += i;
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
	//cin >> t;
	Sieve();
	fr(i, 0, t)
	{
		solve();
	}
}