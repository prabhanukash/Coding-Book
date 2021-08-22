// Problem Link -https://www.geeksforgeeks.org/maximum-level-sum-in-n-ary-tree/
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
    vector<Node *> child;
};
Node *newNode(ll d)
{
    Node *tmp = new Node();
    tmp->data = d;
    return tmp;
}
ll mx_nodes_on_level_cnt(Node *root)
{
    queue<Node *> q;
    q.push(root);
    ll ans = root->data;
    while (q.empty() == false)
    {
        ll sz = q.S;

        ll mx = 0;
        while (sz--)
        {
            Node *tmp = q.front();
            q.pop();
            mx += tmp->data;
            for (auto i : tmp->child)
            {
                q.push(i);
            }
        }
        ans = max(ans, mx);
    }
    return ans;
}
void solve()
{
    //     1
    //    / \
    //   2   3
    //  /|\  /|\\
    //  456  78910
    Node *root = newNode(1);
    root->child.push_back(newNode(2));
    root->child.push_back(newNode(3));
    root->child[0]->child.push_back(newNode(4));
    root->child[0]->child.push_back(newNode(5));
    root->child[0]->child.push_back(newNode(6));
    root->child[1]->child.push_back(newNode(7));
    root->child[1]->child.push_back(newNode(8));
    root->child[1]->child.push_back(newNode(9));
    root->child[1]->child.push_back(newNode(10));
    cout << mx_nodes_on_level_cnt(root) << '\n';
}

signed main()
{
    fast();
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll t = 1;
    //cin >> t;
    fr(i, 0, t)
    {
        solve();
    }
}