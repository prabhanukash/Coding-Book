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
/*Problem Link : https://www.lintcode.com/problem/516/*/
void solve()
{
	ll n, k;
	cin >> n >> k;
	ll a[n][k];
	ll dp[n][k];
	ll mx1, mx2;
	mx1, mx2 = INT_MAX;
	fr(i, 0, n)
	{
		fr(j, 0, n)
		{
			cin >> a[i][j];

			if (i == 0)
			{
				dp[i][j] = a[i][j];
				if (a[i][j] <= mx1)
				{
					mx2 = mx1;
					mx1 = a[i][j];
				}
				else if (a[i][j] <= mx2)
				{
					mx2 = a[i][j];
				}
			}
		}
	}
	fr(i, 1, n)
	{
		ll least = INT_MAX;
		ll sleast = INT_MAX;
		fr(j, 0, n)
		{
			if (dp[i - 1][j] == mx1)
			{
				dp[i][j] = a[i][j] + mx2;
			}
			else
			{
				dp[i][j] = a[i][j] + mx1;
			}
			if (dp[i][j] <= least)
			{
				sleast = least;
				least = dp[i][j];
			}
			else if (dp[i][j] <= sleast)
			{
				sleast = dp[i][j];
			}
		}
		mx1 = least;
		mx2 = sleast;
	}
	cout << mx1 << '\n';
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