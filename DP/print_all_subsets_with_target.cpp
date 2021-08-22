// Problem Link -
/* By Bhanu Prakash */
#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
#define ll long long int
#define ff first
#define ss second
#define S size()
#define mod (ll)(1e9 + 7)
#define inf 1e18
#define fr(i, x, y) for (ll i = x; i < y; i++)
#define dr(i, x, y) for (ll i = x; i >= y; i--)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define mapcl map<char, ll>
#define mapll map<ll, ll>
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
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;
void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
//----------------------------------------FUNCTIONS-------------------------------------
const ll N = (ll)(1 * 1e6 + 5);
ll dp[1000][1000];
struct item
{
	ll i;
	ll j;
	string osf;
};
ll subset_target(ll a[], ll n, ll tar)
{
	if (tar == 0)
	{
		dp[n][tar] = 1;
		return 1;
	}

	if (n == 0)
	{
		dp[n][tar] = 0;
		return 0;
	}

	if (dp[n][tar] != -1)
		return dp[n][tar];

	if (a[n - 1] > tar)
		return dp[n][tar] = subset_target(a, n - 1, tar);

	return dp[n][tar] = subset_target(a, n - 1, tar - a[n - 1]) || subset_target(a, n - 1, tar);
}
void solve()
{
	ll n;
	cin >> n;
	ll tar;
	cin >> tar;
	ll a[n];
	fr(i, 0, n) cin >> a[i];
	memset(dp, -1, sizeof(dp));

	if (subset_target(a, n, tar))
		cout << "YES\n";
	else
		cout << "NO\n";

	fr(i, 0, n + 1)
	{
		fr(j, 0, tar + 1)
		{
			if (dp[i][j] == -1)cout << "X ";
			else cout << dp[i][j] << ' ';

		}
		cout << '\n';
	}

	queue<item> q;
	// q.push({n, tar, ""});
	// while (q.empty() == false)
	// {
	// 	item p = q.front();
	// 	q.pop();
	// 	if (p.i == 0 or p.j == 0)
	// 	{
	// 		cout << p.osf << '\n';
	// 	}
	// }
	/*
			7
	*/

}

signed main()
{
	fast();
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ll t = 1;
	//cin >> t;
	fr(i, 0, t)
	{
		solve();
	}
}