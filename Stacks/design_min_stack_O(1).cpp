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
class MinStack
{
public:
	stack<ll>data;
	ll mn;
	ll size()
	{
		return data.S;
	}
	void push(ll d)
	{
		if (data.size() == 0)
		{
			mn = d;
			data.push(d);
		}
		else if (d >= mn)
		{
			data.push(d);
		}
		else if (d < mn)
		{
			data.push(d + d - mn);
			mn = d;
		}
	}
	ll pop()
	{
		if (data.size() == 0)
		{
			cout << "stack underflow\n";
			return -1;
		}
		if (data.top() >= mn)
		{
			ll val = data.top();
			data.pop();
			return val;
		}
		else
		{
			ll ov = mn;
			mn = 2 * mn - data.top();
			data.pop();
			return mn;
		}
	}
	ll top()
	{
		if (data.S == 0)
		{
			cout << "stack underflow\n";
			return -1;
		}
		if (data.top() >= mn)
		{
			return data.top();
		}
		else
		{
			return mn;
		}
	}
	ll min()
	{
		if (data.S == 0)
		{
			cout << "stack underflow\n";
			return -1;
		}
		else return mn;
	}
};
void solve()
{
	MinStack st;
	st.push(8);
	st.push(2);
	st.push(0);
	st.push(4);
	cout << st.min() << '\n';
	st.pop();
	st.pop();
	st.push(-5);
	cout << st.min() << '\n';
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