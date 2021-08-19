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
	Node* next;
	Node(ll d)
	{
		data = d;
		next = NULL;
	}
};
Node* reverse(Node* head)
{
	Node* prev = NULL;
	Node* curr = head;
	Node* next;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;

	}
	return prev;
}
void print(Node* head) {
	Node* tmp = head;
	while (tmp != NULL)
	{
		cout << tmp->data << ' ';
		tmp = tmp->next;
	}
	cout << '\n';
}
bool checkPalindrome(Node* head)
{
	if (head == NULL and head->next == NULL)return true;
// find middle
	Node* slw_ptr = head;
	Node* fast_ptr = head;
	while (fast_ptr and fast_ptr->next)
	{
		slw_ptr = slw_ptr->next;
		fast_ptr = fast_ptr->next->next;
	}
	slw_ptr->next = reverse(slw_ptr->next);
	slw_ptr = slw_ptr->next;
	while (slw_ptr)
	{
		if (head->data != slw_ptr->data)
		{
			return false;
		}
		head = head->next;
		slw_ptr = slw_ptr->next;
	}
	return true;
}
void solve()
{
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(3);
	head->next->next->next->next = new Node(4);
	head->next->next->next->next->next = new Node(1);
	print(head);
	cout << checkPalindrome(head) << '\n';

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