#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
#define ff first
#define ss second
#define S size()
#define mod (ll)(1e9 + 7)
#define mset(a, k) memset(a, k, sizeof(a))
#define fr(i, x, y) for (ll i = x; i < y; i++)
#define dr(i, x, y) for (ll i = x; i >= y; i--)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define mapcl map<char, ll>
#define mapll map<ll, ll>
#define mapsl map<string, ll>
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
	int data;
	Node* left;
	Node* right;
	Node* nextRight;
};

Node* newNode(int data)
{
	Node* n = new Node();
	n->data = data;
	n->left = NULL;
	n->right = NULL;

	return (n);
}
void connect_adjacenet(Node* root)
{
	queue<Node*> q;
	q.push(root);
	Node* temp = NULL; // initializing prev to null
	while (!q.empty()) {
		ll n = q.size();
		for (ll i = 0; i < n; i++) {
			Node* prev = temp;
			temp = q.front();
			q.pop();

			// i > 0 because when i is 0 prev points
			// the last node of previous level,
			// so we skip it
			if (i > 0)
				prev->nextRight = temp;

			if (temp->left)
				q.push(temp->left);

			if (temp->right)
				q.push(temp->right);
		}

		// pointing last node of the nth level to null
		temp->nextRight = NULL;
	}
}
void solve()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	connect_adjacenet(root);
	cout << root->left->nextRight->data << '\n';
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