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
ll least_cost_path(vvi &a, ll n, ll m)
{
	if (n < 0 || m < 0) return INT_MAX;
	if (dp[n][m] != -1)return dp[n][m];
	if (n == 0 and m == 0)return a[0][0];
	return dp[n][m] = a[n - 1][m - 1] + min({least_cost_path(a, n - 1, m), least_cost_path(a, n, m - 1)});
}
void solve()
{
	ll n, m;
	cin >> n >> m;
	vvi a(n, vi(m));
	fr(i, 0, n)
	{
		fr(j, 0, m)cin >> a[i][j];
	}
	least_cost_path(a, n, m);
	cout << dp[0][0] << '\n';
	queue<pair<string , pii>>q;
	q.push({"", {0, 0}});
	while (q.empty() == false)
	{
		pair<string, pii> p = q.front();
		q.pop();
		string osf = p.ff;
		ll i = p.ss.ff;
		ll j = p.ss.ss;
		if (i == n - 1 and j == m - 1)
		{
			cout << osf << '\n';
		}
		else if (i == n - 1)
		{
			q.push({osf + "H", {i, j + 1}});
		}
		else if (j == m - 1)
		{
			q.push({osf + "V", {i + 1, j}});
		}
		else
		{
			if (dp[i][j + 1] < dp[i + 1][j])
			{
				q.push({osf + "H", {i, j + 1}});
			}
			else if (dp[i][j - 1] > dp[i + 1][j])
			{
				q.push({osf + "V", {i + 1, j}});
			}
			else
			{
				q.push({osf + "H", {i, j + 1}});
				q.push({osf + "V", {i + 1, j}});
			}
		}
	}

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