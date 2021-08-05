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

ll fact(ll n)
{
	if (n == 1)return 1;
	ll sp = fact(n - 1);
	return n * sp;
}
ll fib(ll n)
{
	if (n == 0)return 0;
	if (n == 1)return 1;
	ll sp1 = fib(n - 1);
	ll sp2 = fib(n - 2);
	return sp1 + sp2;

}
ll power(ll a, ll p)
{
	if (p == 0)return 1;
	if (p == 1)return a;
	ll sp = power(a, p / 2);
	if (p % 2 == 0)return sp * sp;
	else return a * sp * sp;

}
void printRec(ll a[], ll n, ll i)
{
	if (i == n - 1)
	{
		cout << a[i] << ' ';
		return;
	}
	cout << a[i] << ' ';
	printRec(a, n, i + 1);
	cout << a[i] << ' ';
}
ll concec_ones(ll n)
{
	if (n == 1)return 2;
	if (n == 2)return 3;
	return concec_ones(n - 1) + concec_ones(n - 2);
}
ll ways_to_party(ll n)
{

	if (n == 1)return 1;
	if (n == 2)return 2;
	ll alone_sp = ways_to_party(n - 1);
	ll pair_sp = (n - 1) * ways_to_party(n - 2);
	return alone_sp + pair_sp;
}
void printPattern(ll n, ll i)
{
	if (n == 0)return;
	if (i > 0)
	{
		cout << "* ";
		printPattern(n, i - 1);

	}
	else
	{
		cout << '\n';
		printPattern(n - 1, );
	}
}
void printSubsets(ll a[], ll i, ll n, string osf)
{
	if (i == n)
	{
		cout << "[" + osf + "]" << '\n';
		return;
	}
	printSubsets(a, i + 1, n, osf + to_string(a[i]));
	printSubsets(a, i + 1, n, osf);
}
void solve()
{
	// ll n;
	// cin >> n;
	// cout << fact(n) << '\n';
	// cout << fib(n) << '\n';
	// ll a, p;
	// cin >> a >> p;
	// cout << pow(a, p) << '\n';
	// ll n;
	// cin >> n;
	// ll a[n];
	// fr(i, 0, n)cin >> a[i];
	// printRec(a, n, 0);
	// cout << concec_ones(3) << '\n';
	// cout << ways_to_party(3) << '\n';
	// cout << power(2, 5) << '\n';
	printPattern(5, 1);
	// ll n;
	// cin >> n;
	// ll a[3] = {1, 2, 3};
	// printSubsets(a, 0, 3, "");
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