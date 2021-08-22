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
    char data;
    unordered_map<char, Node *> child;
    bool isTerminal;
    Node(char d)
    {
        this->data = d;
        this->isTerminal = false;
    }
};
class Trie
{
public:
    bool flg;
    Node *root;
    Trie()
    {
        root = new Node('\0');
        flg = true;
    }
    void insert(string s)
    {
        Node *curr = root;
        fr(i, 0, s.S)
        {
            char ch = s[i];
            if (curr->child.count(ch))
            {
                curr = curr->child[ch];
                if (curr->isTerminal)
                {
                    flg = false;
                }
            }
            else
            {
                Node *n = new Node(ch);
                curr->child[ch] = n;
                curr = curr->child[ch];
            }
        }
        curr->isTerminal = true;
        if (curr->child.empty() == false)
            flg = false;
    }
    // bool search(string s)
    // {
    //     Node *curr = root;
    //     fr(i, 0, s.S)
    //     {
    //         char ch = s[i];
    //         if (curr->child.count(ch))
    //         {
    //             curr = curr->child[ch];
    //         }
    //         else
    //         {
    //             return false;
    //         }
    //     }
    //     return curr->isTerminal == true;
    // }
    // void helperDFS(Node *root, string s, string osf)
    // {
    //     if (root == NULL)
    //         return;
    //     if (root->isTerminal)
    //         cout << s + osf << '\n';

    //     for (auto i : root->child)
    //     {
    //         helperDFS(i.ss, s, osf + i.ff);
    //     }
    // }
    // void getPrefixes(string s)
    // {
    //     Node *curr = root;
    //     fr(i, 0, s.S)
    //     {
    //         char ch = s[i];
    //         if (curr->child.count(ch))
    //         {
    //             curr = curr->child[ch];
    //         }
    //         else
    //         {
    //             cout << "the query is not present as the prefix\n";
    //             return;
    //         }
    //     }
    //     helperDFS(curr, s, "");
    // }
};
void solve()
{
    ll n;
    cin >> n;
    Trie t;
    while (n--)
    {
        string s;
        cin >> s;
        if (t.flg == true)
            t.insert(s);
    }
    if (t.flg)
        cout << "YES\n";
    else
        cout << "NO\n";
}

signed main()
{
    fast();
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll t = 1;
    cin >> t;
    fr(i, 0, t)
    {
        solve();
    }
}