// Problem Link -https://www.geeksforgeeks.org/maximum-xor-of-two-numbers-in-an-array/
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
class Node
{
public:
	Node* left;
	Node* right;
};
void insert(Node* root, ll val)
{
	Node* curr = root;
	for (ll i = 31; i >= 0; i--)
	{
		ll b = (val >> i) & 1;
		if (b == 0)
		{
			if (!curr->left)curr->left = new Node();
			curr = curr->left;
		}
		else
		{
			if (!curr->right)curr->right = new Node();
			curr = curr->right;
		}
	}
}
ll max_xor_pair(ll a[], ll n, Node* root)
{
	ll mx = INT_MIN;
	fr(i, 0, n)
	{
		Node* curr = root;
		ll val = a[i];
		ll curr_xor = 0;
		for (ll j = 31; j >= 0; j--)
		{
			ll b = (val >> j) & 1;
			if (b == 0)
			{
				if (curr->right)
				{
					curr_xor += pow(2, j);
					curr = curr->right;
				}
				else
				{
					curr = curr->left;
				}
			}
			else
			{
				if (curr->left)
				{
					curr_xor += pow(2, j);
					curr = curr->left;
				}
				else
				{
					curr = curr->right;
				}
			}
		}
		mx = max(mx, curr_xor);
	}
	return mx;

}
void solve()
{
	ll n;
	cin >> n;
	ll a[n];
	Node* root = new Node();
	fr(i, 0, n)
	{
		cin >> a[i];
		insert(root, a[i]);
	}
	cout << max_xor_pair(a, n, root);
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