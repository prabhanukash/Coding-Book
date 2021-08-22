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
class LRUCache
{
private:
	ll capacity;
	list<ll> recentList;
	unordered_map<ll, list<ll>::iterator>position;
	unordered_map<ll, ll> cache;
public:
	LRUCache(ll k)
	{
		capacity = k;
	}
	bool isPresentInCache(ll key)
	{
		return cache.find(key) != cache.end();
	}
	ll get(ll key)
	{
		if (isPresentInCache(key))
		{
			use(key);
			return cache[key];
		}
		else return -1;
	}
	void use(ll key) {
		if (isPresentInCache(key))
		{
			recentList.erase(position[key]);
		}
		else if (recentList.size() >= capacity)
		{
			ll lru = recentList.back();
			recentList.pop_back();
			cache.erase(lru);
			position.erase(lru);

		}
		recentList.push_front(key);
		position[key] = recentList.begin();
	}
	void update(ll key, ll val)
	{
		use(key);
		cache[key] = val;
	}
	void print()
	{
		for (auto it : recentList)
		{
			cout << it << ' ';
		}
		cout << '\n';
	}
};
void solve()
{
	LRUCache c(3);
	c.update(1, 123);
	c.update(2, 234);
	c.update(1, 456);
	c.update(3, 345);
	c.print();
	c.update(4, 444);
	c.print();
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