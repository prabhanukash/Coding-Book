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
class Node
{
public:
	ll data;
	Node* left, *right;
	Node(ll d)
	{
		this->data = d;
		this->left = this->right = NULL;
	}
};
void inorder(Node* root)
{
	if (root == NULL)return;
	inorder(root->left);
	cout << root->data << ' ';
	inorder(root->right);
}
void preorder(Node* root)
{
	if (root == NULL)return;
	cout << root->data << ' ';
	preorder(root->left);
	preorder(root->right);
}
void postorder(Node* root)
{
	if (root == NULL)return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << ' ';
}
void level_order(Node* root)
{
	queue<Node*> q;
	q.push(root);
	while (q.empty() == false)
	{
		Node* tmp = q.front();
		q.pop();
		cout << tmp->data << ' ';
		if (tmp->left)q.push(tmp->left);
		if (tmp->right)q.push(tmp->right);
	}
}
void spiral_level_order(Node* root)
{
	queue<Node*> q;
	q.push(root);
	vi ans;
	ll flg = 0;
	while (!q.empty())
	{
		//cout << flg << '\n';
		vi ans;
		ll sz = q.S;
		while (sz--)
		{
			Node* tmp = q.front();
			q.pop();
			ans.pb(tmp->data);
			if (tmp->left)q.push(tmp->left);
			if (tmp->right)q.push(tmp->right);
		}
		if (flg)reverse(all(ans));
		for (auto i : ans)cout << i << ' ';
		flg = 1 - flg;
	}
}
ll mx_lev = -1;
void left_view(Node*root, ll lev)
{
	if (root == NULL)return;
	if (mx_lev < lev) {
		cout << root->data << ' ';
		mx_lev = lev;
	}
	if (root->left)left_view(root->left, lev + 1);
	if (root->right)left_view(root->right, lev + 1);
}
void right_view(Node* root, ll lev)
{
	if (root == NULL)return;
	if (mx_lev < lev)
	{
		cout << root->data << ' ';
		mx_lev = lev;
	}
	if (root->right)right_view(root->right, lev + 1);
	if (root->left)right_view(root->left, lev + 1);
}
map<ll, vi> m;
void top_view(Node* root, ll hd)
{
	if (root == NULL)return;
	m[hd].pb(root->data);
	if (root->left)top_view(root->left, hd - 1);
	if (root->right)top_view(root->right, hd + 1);
}
ll height(Node* root)
{
	if (root == NULL)return 0;
	ll lh = height(root->left);
	ll rh = height(root->right);
	return 1 + max(lh, rh);
}
void mirror(Node* root)
{
	if (root == NULL)return ;
	mirror(root->right);
	mirror(root->left);
	swap(root->left , root->right);
}
ll mx;
void maxSumRoot_Leaf(Node* root, ll sum)
{
	if (root == NULL)return;
	if (root->left == NULL and root->right == NULL and root->data + sum > mx)
	{
		mx = root->data + sum;
		return;
	}
	maxSumRoot_Leaf(root->left, root->data + sum);
	maxSumRoot_Leaf(root->right, root->data + sum);

}

void solve()
{
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	// inorder(root);
	// cout << '\n';
	// preorder(root);
	// cout << '\n';
	// postorder(root);
	// cout << '\n';
	// level_order(root);
	// cout << '\n';
	// spiral_level_order(root);
	// left_view(root, 0);
	// mx_lev = -1;
	// cout << '\n';
	// right_view(root, 0);
	// cout << '\n';
	// top_view(root, 0);
	// for (auto i : m)
	// {
	// 	cout << i.ss[0] << ' ';
	// }
	// cout << '\n';
	// for (auto i : m)
	// {
	// 	cout << i.ss[i.ss.S - 1] << ' ';
	// }
	//cout << height(root) << '\n';
	// inorder(root);
	// cout << '\n';
	// mirror(root);
	// inorder(root);
	maxSumRoot_Leaf(root, 0);
	cout << mx << '\n';
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