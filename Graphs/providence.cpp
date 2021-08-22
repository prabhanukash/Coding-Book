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
bool vis[505][505];
ll dx[4] = {0, -1, 1, 0};
ll dy[4] = {1, 0, 0, -1};
bool issafe(ll x, ll y, ll n, ll m, vvi &a, ll p)
{
	return (x >= 0 and x<n and y >= 0 and y < m and vis[x][y] == false and a[x][y] == p );//
}
ll flg = false;
void dfs(ll sx, ll sy, ll ex, ll ey, ll n, ll m, ll p, vvi &a)
{
	//cout << sx << ' ' << sy << '\n';
	vis[sx][sy] = true;
	// if (sx == ex and sy == ey and a[sx][ex] == p)
	// {
	// 	flg = true;
	// 	return;
	// }
	fr(i, 0, 4)
	{
		ll x = dx[i] + sx;
		ll y = dy[i] + sy;

		if (issafe(x, y, n, m, a, p)) {
			cout << x << ' ' << y << '\n';
			dfs(x, y, ex, ey, n, m, p, a);
		}
	}
}
ll spf[N];
mapll pf;
void compute(ll n)
{
	fr(i, 0, N)spf[i] = i;
	for (ll i = 4; i < N; i += 2)spf[i] = 2;
	for (int i = 3; i * i < N; i++)
	{
		if (spf[i] == i)
		{
			for (int j = i * i; j < N; j += i)

				if (spf[j] == j)
					spf[j] = i;
		}
	}

}
ll prime_count(ll n)
{
	while (n != 1)
	{
		pf[spf[n]]++;
		n = n / spf[n];
	}
	return pf.S;
}
void solve()
{
	ll n, m;
	cin >> n >> m;
	vvi a(n, vi(m));
	// input
	fr(i, 0, n)
	{
		fr(j, 0, m)
		{
			cin >> a[i][j];
		}
	}
	// changing a[i][j]=prime_count
	fr(i, 0, n)
	{
		fr(j, 0, m)
		{
			pf.clear();
			if (a[i][j] > 0)a[i][j] = prime_count(a[i][j]);
			else a[i][j] = 0;
		}
	}
	fr(i, 0, n)
	{
		fr(j, 0, m)
		{
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	ll q;
	cin >> q;
	while (q--)
	{
		pf.clear();
		memset(vis, false, sizeof(vis));
		ll sx, sy, ex, ey, p;
		cin >> sx >> sy >> ex >> ey >> p;
		if (a[sx][sy] == p)
		{
			dfs(sx, sy, ex, ey, n, m, p, a);
			if (vis[ex][ey])cout << "Yes\n";
			else cout << "No\n";
		}
		else cout << "No\n";
		fr(i, 0, n)
		{
			fr(j, 0, m)
			{
				cout << vis[i][j] << ' ';
			}
			cout << '\n';
		}
	}
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
		compute(N);
		solve();
	}
}