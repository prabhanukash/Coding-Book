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
ll n;
bool isSafe(vector<vector<int> >&grid, vector < vector<bool>> &vis, ll i, ll j, ll n)
{
	return (i >= 0 and j >= 0 and j < n and i < n and vis[i][j] == false);
}
void displayGrid(vector<vector<int>>&grid)
{
	fr(i, 0, n)
	{
		fr(j, 0, n)
		{
			cout << grid[i][j] << ' ';
		}
		cout << '\n';
	}
}
void canCoverKnight(vector < vector<int> >&grid, vector < vector<bool> > &vis, ll count, ll x, ll y, ll n)
{
	if (count == n * n - 1)
	{
		grid[x][y] = count;
		displayGrid(grid);
		cout << '\n';

		return;
	}
	if (count >= n * n)return;
	ll dx[8] = { -2, -2, -1, -1, 2, 2, 1, 1};
	ll dy[8] = {1, -1, 2, -2, 1, -1, 2, -2};
	vis[x][y] = true;
	grid[x][y] = true;
	grid[x][y] = count;
	fr (i, 0, 8)
	{
		ll X = dx[i] + x;
		ll Y = dy[i] + y;
		if (isSafe(grid, vis, X, Y, n))
		{
			canCoverKnight(grid, vis, count + 1, X, Y, n);
		}
	}
	grid[x][y] = -1;
	vis[x][y] = false;
}
void solve()
{
	//ll n;
	cin >> n;
	vector < vector<int> > grid(n, vector<int> (n, -1));
	vector < vector<bool> > vis(n, vector<bool>(n, false));
	canCoverKnight(grid, vis, 0, 0, 0, n);
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