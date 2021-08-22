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
#define vvb vector<vb>
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
void displayGrid(vvb &vis, ll n)
{
	fr(i, 0, n)
	{
		fr(j, 0, n)
		{
			if (vis[i][j])cout << 1 << ' ';
			else cout << 0 << ' ';
		}

		cout << '\n';
	}
}
ll totPaths;
bool isSafe(ll i, ll j, ll n, ll m, vector<vector<bool>> &vis)
{
	return (i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == false);
}
void helper(ll i, ll j, ll n, ll m, vector <vector<char>> &grid, vvb &vis)
{
	if (i == n - 1 && j == m - 1)
	{
		totPaths++;
		//displayGrid(vis, n);
		return;
	}
	if (not isSafe(i, j, n, m, vis))return;
	vis[i][j] = true;
	if (i + 1 < n and grid[i + 1][j] == '.') // down
	{
		helper(i + 1, j, n, m, grid, vis);
	}
	if (j + 1 < m and grid[i][j + 1] == '.') // right
	{
		helper(i , j + 1, n, m, grid, vis);
	}
	// if (i - 1 >= 0 and grid[i - 1][j] == 0) // up
	// {
	// 	helper(i - 1, j, n, grid, vis);
	// }
	// if (j - 1 >= 0 and grid[i][j - 1] == 0) // left
	// {
	// 	helper(i, j - 1, n, grid, vis);
	// }
	vis[i][j] = false;
	return;

}
ll countRatMaze( vector < vector<char>> &grid)
{
	ll n = grid.size();
	ll m = grid[0].size();
	vvb vis(n, vector<bool>(m, false));
	helper(0, 0, n, m, grid, vis);
	return totPaths;
}
void solve()
{
	ll n, m;
	cin >> n >> m;
	vector < vector<char>> grid(n, vector <char> (m));
	fr(i, 0, n)
	{
		fr(j, 0, m)
		{
			cin >> grid[i][j];
		}
	}
	cout << countRatMaze(grid) << '\n';
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