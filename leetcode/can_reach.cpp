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
ll min_jumps(ll a[], ll n)
{
	if (n == 1 || n == 0) return 0;
	ll last_max_coverage = a[0];
	ll jumps = 1;
	ll next_max_covergae = a[0];
	for (ll i = 1; i < n; i++)
	{
		if (last_max_coverage < i)
		{
			jumps++;
			last_max_coverage = next_max_covergae;
			if (last_max_coverage >= n - 1)return jumps;
		}
		next_max_covergae = max(next_max_covergae, a[i] + i);
	}
	return jumps;
}
void solve()
{
	ll n;
	cin >> n;
	ll a[n];
	fr(i, 0, n)cin >> a[i];
	ll last_pos = n - 1;
	cout << min_jumps(a, n);
	/*for (ll i = n - 2; i >= 0; i--)
	{
		if (i + a[i] >= last_pos)last_pos = i;
	}
	if (last_pos == 0)
	{
		cout << "YES\n";
	}
	else cout << "NO\n";*/
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
	fr(i, 0, t)
	{
		solve();
	}
}