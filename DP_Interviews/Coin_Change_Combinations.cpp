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
// Problem Link : https://leetcode.com/problems/coin-change-2/
void solve()
{
	ll n;
	cin >> n;
	ll a[n]; // different denominations of the coins
	fr(i, 0, n)cin >> a[i];
	ll tar;
	cin >> tar;
	ll dp[tar + 1] = {}; // we have assigned storage
	// here dp[i] will represent number of ways to make change i
	// we move from smaller problem to bigger problem
	dp[0] = 1;
	for (ll i = 0; i < n; i++) // first we don't know about next denominations
	{
		fr(j, a[i], tar + 1)
		{
			dp[j] = dp[j] + dp[j - a[i]];
		}
	}
	cout << dp[tar] << '\n';
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