// Problem Link -https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/dynamic-programming/lis-re-official/ojquestion
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
struct item
{
	ll l;
	ll i;
	ll val;
	string osf;
};
void solve()
{
	ll n;
	cin >> n;
	ll a[n];
	fr(i, 0, n)cin >> a[i];
	ll dp[n];
	dp[0] = 1;
	ll ans = 0;
	ll ans_pos;
	fr(i, 1, n)
	{
		ll mx = 0;
		fr(j, 0, i)
		{
			if (a[j] < a[i])
			{
				mx = max(mx, dp[j]);
			}
		}
		dp[i] = mx + 1;
		if (ans < dp[i])
		{
			ans = dp[i];
			ans_pos = i;
		}
	}
	cout << ans << ' ' << ans_pos << '\n';
	queue<item> q;
	q.push({ans, ans_pos, a[ans_pos], to_string(a[ans_pos])});
	while (q.empty() == false)
	{
		item p = q.front();
		q.pop();
		if (p.l == 1)
		{
			cout << p.osf << '\n';
		}
		for (ll j = p.i; j >= 0; j--)
		{
			if (dp[j] == p.l - 1 and p.val >= a[j])
			{
				q.push({dp[j], j, a[j], to_string(a[j]) + " " + p.osf});
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