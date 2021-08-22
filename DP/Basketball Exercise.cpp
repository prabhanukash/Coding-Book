// Problem Link - https://codeforces.com/problemset/problem/1195/C
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
the question is about we will be given two arrays of size n with integer values we need to find
the total sum of elements of subset choosen such that we need to choose elements in a way that it
should be greater than previous index choosen and also it shouldn't be from the same array

tc :

3
1 2 9
10 1 1

here we can think that 10 2 1 but ans is 10 + skip(0) + 9

here we need to divide into subproblems

smallest subproblem is when we have single elements in both arrays then  max of a[0], b[0]

for curr i we some how know the ans for i-1
	then
	dp[i] => either we can choose this part of ans (dp[i-1]+a[i]) or we can skip this (dp[i-1])
	but here we have constraint that we don't need to choose from same array
	then
	dp[i][0] = max(dp[i-1][1]+a[i],dp[i-1][0])
	dp[i][1] = max(dp[i-1][0]+b[i],dp[i-1][1])
*/
void solve()
{
	ll n;
	cin >> n;
	ll a[n], b[n];
	fr(i, 0, n)cin >> a[i];
	fr(i, 0, n)cin >> b[i];

	ll dp[n][2];// 0->a 1->b
	dp[0][0] = a[0];
	dp[0][1] = b[0];
	fr(i, 1, n)
	{
		dp[i][0] = max(dp[i - 1][1] + a[i], dp[i - 1][0]);
		dp[i][1] = max(dp[i - 1][0] + b[i], dp[i - 1][1]);
	}
	cout << max(dp[n - 1][0], dp[n - 1][1]) << '\n';

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