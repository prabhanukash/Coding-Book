// Problem Link -https://codeforces.com/problemset/problem/245/H
/* By Bhanu Prakash */
#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
#define ll  int
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
const ll N = (ll)(5 * 1e3 + 5);
/*
the question is about we will be given a string and we will be q queries
	for each query l,r we need to find the number palindromic substrings for substring l,r
so every time we need to calcutate it for l,r

here  for i..j if we know some how nps for i+1...j-1 then we need to calculate some more substrings
for i..j apart from that they are  i..j , i+1..j , i..j-1
=> dp[i][j]=nps(i+1,j)+nps(i,j-1)-nps(i+1,j-1)+isPal(i,j);

here isPal(i,j) checks whether i..j is palindrome or not we will do it with separate dp
*/
string s;
ll dp[N][N];
ll pal[N][N];
ll isPal(ll i, ll j)
{
	if (i == j)return 1;
	if (i + 1 == j)return (s[i] == s[j]);
	if (pal[i][j] != -1)return pal[i][j];
	return pal[i][j] = isPal(i + 1, j - 1) && (s[i] == s[j]) ? 1 : 0;
}
ll nps(ll i, ll j)
{
	if (i == j)return 1;
	if (i + 1 == j)return 2 + isPal(i, j);
	if (dp[i][j] != -1)return dp[i][j];
	return dp[i][j] = nps(i, j - 1) + nps(i + 1, j) - nps(i + 1, j - 1) + isPal(i, j);
}
void solve()
{
	cin >> s;
	memset(pal, -1, sizeof(pal));
	memset(dp, -1, sizeof(dp));
	ll q;
	cin >> q;
	while (q--)
	{
		ll l, r;
		cin >> l >> r;
		cout << nps(l - 1, r - 1) << '\n';
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