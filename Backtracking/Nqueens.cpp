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
ll qcount;
ll n;
bitset < 100> col, ld, rd;
void displayGrid(vvi &grid, ll n)
{
	fr(i, 0, n)
	{
		fr(j, 0, n)
		{
			if (grid[i][j])cout << "Q\t";
			else cout << "-\t";
		}
		cout << '\n';
	}
	cout << '\n';
}
void Nqueen(ll curr_row, vvi &grid)
{
	if (curr_row == n) {
		qcount++;
		displayGrid(grid, n);
		return;
	}
	fr(i, 0, n) {
		if (col[i] || rd[i + curr_row] || ld[i - curr_row + n - 1])continue;
		col[i] = rd[i + curr_row] = ld[i - curr_row + n - 1] = grid[curr_row][i] = 1;
		Nqueen(curr_row + 1, grid);
		col[i] = rd[i + curr_row] = ld[i - curr_row + n - 1] = grid[curr_row][i] = 0;
	}
}
void solve()
{
	//ll n;
	cin >> n;
	qcount = 0;
	vvi grid(n, vi(n, 0));
	Nqueen(0, grid);
	if (qcount == 0)cout << "Not Possible\n";
}

signed main()
{
	fast();
#ifndef ONLINE_JUDGE
	freopen ("inp.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif
	ll t = 1;
	//ll t;
	fr(i, 0, t)
	{
		//cout << t + 1 << ".\n";
		solve();
		//cout << qcount << '\n';
	}
}