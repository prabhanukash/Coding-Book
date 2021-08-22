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
	Node* left;
	Node* right;
	ll height;
	Node(ll d)
	{
		this->data = d;
		this->left = this->right = NULL;
		this->height = 1;
	}
};
ll H(Node* n)
{
	if (n == NULL)return 0;
	return n->height;
}
ll getBalanceFactor(Node* n)
{
	if (n == NULL)return 0;
	return H(n->left) - H(n->right);
}
Node* leftRotate(Node* root)
{
	/*

		1
		 \                  3
		  3      =>        / \
		 / \              1   4
		2   4              \
		                    2
	*/
	Node* new_root = root->right;
	Node* tmp = new_root->left;
	new_root->left = root;
	root->right = tmp;
	root->height = 1 + max(H(root->left), H(root->right));
	new_root-> height = 1 + max(H(new_root->left), H(new_root->right));
	return new_root;


}
Node* rightRotate(Node* root)
{
	/*

		     4
		    /                2
		  2      =>        / \
		 / \              1   4
		1   3                /
		                    3
	*/
	Node* new_root = root->left;
	Node* tmp = new_root->right;
	new_root->right = root;
	root->left = tmp;
	root->height = 1 + max(H(root->left), H(root->right));
	new_root->height = 1 + max(H(new_root->left), H(new_root->right));
	return new_root;

}
Node* insert(Node* root, ll d)
{
	if (root == NULL)return new Node(d);
	if (d < root->data)
	{
		root->left = insert(root->left, d);
	}
	else if (d > root->data)
	{
		root->right = insert(root->right, d);
	}
	else return root;

	root->height = 1 + max(H(root->left), H(root->right));

	ll bf = getBalanceFactor(root); //{-1,0,1}

	//left-left Case
	if (bf > 1 && d < root->left->data)
		return rightRotate(root);

	// Right Right Case
	if (bf < -1 && d > root->right->data)
		return leftRotate(root);

	// Left Right Case
	if (bf > 1 && d > root->left->data)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Left Case
	if (bf < -1 && d < root->right->data)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;

}
void preOrder(Node *root)
{
	if (root != NULL)
	{
		cout << root->data << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}
void solve()
{
	Node *root = NULL;

	/* Constructing tree given in
	the above figure */
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);
	preOrder(root);
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