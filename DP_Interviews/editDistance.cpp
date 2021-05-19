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
ll editDistance(string s1, string s2, ll n, ll m)
{
// base case
	if (m == 0) return 0;
	if (n == 0) return m;
// self work
	if (s1[n] == s2[m])return editDistance(s1, s2, n - 1, m - 1);
	else
	{
		ll op1 = editDistance(s1, s2, n, m - 1); // insert a char s1
		ll op2 = editDistance(s1, s2, n - 1, m); // remove a char from s1
		ll op3 = editDistance(s1, s2, n - 1, m - 1); // replace a char in s1
		return 1 + min({op1, op2, op3});
	}
}
ll editDistance_DP(string s1, string s2)
{
	ll n = s1.S;
	ll m = s2.S;
	ll dp[n + 1][m + 1];
	fr(i, 0, n + 1)
	{
		fr(j, 0, m + 1)
		{
			if (i == 0)dp[i][j] = j;
			else if (j == 0)dp[i][j] = 0;
			else if (s1[i] == s2[j])dp[i][j] = dp[i - 1][j - 1];
			else
			{
				dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
			}
		}
	}
	return dp[n][m];
}
void solve()
{
	string s1, s2;
	cin >> s1 >> s2;
	cout << editDistance(s1, s2, s1.S, s2.S) << '\n';
	cout << editDistance_DP(s1, s2) << '\n';
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