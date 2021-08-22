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
char a[1000][1000];
ll spf[N];
void smallest_prime_factor()
{
	spf[1] = 1;
	for (ll i = 2; i < N ; i++)
		spf[i] = i;

	for (ll i = 4; i < N; i += 2)
		spf[i] = 2;

	for (ll i = 3; i * i < N; i++)
	{

		if (spf[i] == i)
		{
			for (ll j = i * i; j < N; j += i)

				if (spf[j] == j)
					spf[j] = i;
		}
	}
}
mapll m;
ll getFactorization(int x)
{
	while (x != 1)
	{
		m[spf[x]]++;
		x = x / spf[x];
	}
}
void solve()
{
	ll n;
	cin >> n;
	m.clear();
	fr(i, 0, n)
	{
		ll x;
		cin >> x;
		getFactorization(x);
	}
	ll ans = 1;
	for (auto it : m)ans *= (it.ss + 1);
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
	cin >> t;
	smallest_prime_factor();
	fr(i, 0, t)
	{
		solve();
	}
}