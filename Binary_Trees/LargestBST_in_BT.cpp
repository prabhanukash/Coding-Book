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
struct info
{
	ll maxi;
	ll mini;
	ll sz;
	bool isBst;
};
class Node {
public:
	ll data;
	Node* left;
	Node* right;
	Node(ll d)
	{
		data = d;
		left = right = NULL;
	}
};
info largeBst(Node* root) {
	if (root == NULL)
	{
		info tmp;
		tmp.mini = INT_MAX;
		tmp.maxi = INT_MIN;
		tmp.sz = 0;
		tmp.isBst = true;
		return tmp;
	}
	info l = largeBst(root->left);
	info r = largeBst(root->right);
	info res;
	if ((l.isBst and r.isBst) and (root->data > l.maxi) and (root->data < r.mini))
	{
		res.mini = min({l.mini, r.mini, root->data});
		res.maxi = max({l.maxi, r.maxi, root->data});
		res.isBst = true;
		res.sz = l.sz + r.sz + 1;
		return res;
	}
	else
	{
		res.maxi = 0;
		res.mini = 0;
		res.isBst = false;
		res.sz = max(l.sz, r.sz);
		return res;
	}
	return res;

}
void solve()
{
	Node *root = new Node(50);
	root->left = new Node(10);
	root->right = new Node(60);
	root->left->left = new Node(5);
	root->left->right = new Node(20);
	root->right->left = new Node(55);
	root->right->left->left = new Node(45);
	root->right->right = new Node(70);
	root->right->right->left = new Node(65);
	root->right->right->right = new Node(80);
	cout << largeBst(root).sz << '\n';
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