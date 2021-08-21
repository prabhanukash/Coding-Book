// Problem Link -https://leetcode.com/problems/recover-binary-search-tree/
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
class Node {
public:
	ll data;
	Node* left, *right;
	Node(ll d)
	{
		data = d;
		left = right = NULL;
	}
};
void inorder(Node* root)
{
	if (root == NULL)return;
	inorder(root->left);
	cout << root->data << ' ';
	inorder(root->right);
}
vector<pair<Node*, Node*>> vec;
Node* p = NULL;
void reswap(Node* root)
{
	if (root == NULL)return;
	reswap(root->left);
	if (p != NULL and p->data > root->data)vec.pb({p, root});
	p = root;
	reswap(root->right);
}
void solve()
{
	Node* root = new Node(5);
	root->left = new Node(2);
	root->right = new Node(6);
	root->left->left = new Node(3);
	root->left->right = new Node(1);
	reswap(root);
	inorder(root);
	cout << '\n';
	if (vec.size() == 1)
		swap(vec[0].ff->data, vec[0].ss->data);
	if (vec.size() == 2)
		swap(vec[0].ff->data, vec[1].ss->data);
	inorder(root);
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