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
	ll n;
	cin >> n;
	ll a, b, c;
	cin >> a >> b >> c;
	ll dp[n][3];
	dp[0][0] = a;
	dp[0][1] = b;
	dp[0][2] = c;
	fr(i, 1, n)
	{
		cin >> a >> b >> c;
		dp[i][0] = a + max(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = b + max(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = c + max(dp[i - 1][1], dp[i - 1][0]);
	}
	cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << '\n';
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