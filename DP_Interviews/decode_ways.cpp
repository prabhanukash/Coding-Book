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
/*Problem Link : https://leetcode.com/problems/decode-ways/*/
void solve()
{
	string s;
	cin >> s;
	ll n = s.S;
	ll dp[n];
	dp[0] = 1;
	fr(i, 1, n)
	{
		char curr = s[i];
		char prev = s[i - 1];
		if (curr == '0' and prev == '0')
		{
			dp[i] = 0;
		}
		else if ( curr == '0' and prev != '0')
		{
			if (prev == '1' or prev == '2')dp[i] = (i >= 2 ? dp[i - 2] : 1);
			else dp[i] = 0;
		}
		else if (curr != '0' and prev == '0')
		{
			dp[i] = dp[i - 1];
		}
		else
		{
			if (stoi(s.substr(i - 1, i + 1)) < 26)
			{
				dp[i] = dp[i - 1] + (i >= 2 ? dp[i - 2] : 1);
			}
			else
			{
				dp[i] = dp[i - 1];
			}
		}
	}
	// fr(i, '0', n)cout << dp[i] << ' ';
	// cout << '\n';
	cout << dp[n - 1] << '\n';
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