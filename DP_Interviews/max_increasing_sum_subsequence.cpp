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
	ll a[n];
	fr(i, 0, n)cin >> a[i];
	ll dp[n];
	ll maxi = -1;
	fr(i, 0, n)
	{
		ll mx = INT_MIN;
		fr(j, 0, i)
		{
			if (a[j] <= a[i])
			{
				if (mx == INT_MIN)mx = dp[j];
				else if (dp[j] > mx)mx = dp[j];
			}
		}
		if (mx == INT_MIN)dp[i] = a[i];
		else dp[i] = mx + a[i];
		maxi = max(dp[i], maxi);
	}
	cout << maxi << '\n';

}
// Tc => O(N^2)
// SC => O(N)
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