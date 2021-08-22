// Problem Link -https://codeforces.com/problemset/problem/1221/D
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
/*
here we will be given an array of integers we need make change of the array any number of times
but the cost for changing a[i] every time is b[i] rubles we need to make the array speacial
by with min rubles here special array means there are no adjacent elements which are same


first key point is for increasing a[i] we just need threee options inorder make adjacent elements
not equal they are {+0,+1,+2}

so we will define dp such a way that
	dp[i][j] represents   min ans until with j addition to the a[i]

	recurrance :
	 dp[i][j]= min{dp[i-1][0],dp[i-1][1],dp[i-1][2]}+b[i]*j


*/
void solve()
{
	ll n;
	cin >> n;
	ll a[n], b[n];
	fr(i, 0, n)cin >> a[i] >> b[i];
	ll dp[n][3];
	dp[0][0] = 0;
	dp[0][1] = b[0];
	dp[0][2] = 2 * b[0];
	fr(i, 1, n)
	{
		fr(j, 0, 3)
		{
			ll mn = inf;
			fr(p, 0, 3)
			{
				if (a[i - 1] + p != a[i] + j)mn = min(mn, dp[i - 1][p] + j * b[i]);
			}
			dp[i][j] = mn;
		}
	}
	cout << min({dp[n - 1][0], dp[n - 1][2], dp[n - 1][1]}) << '\n';
}

signed main()
{
	fast();
#ifndef ONLINE_JUDGE
	freopen ("inp.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif
	ll t = 1;
	cin >> t;
	fr(i, 0, t)
	{
		solve();
	}
}