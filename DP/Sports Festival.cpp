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
/*Here the question is basically we are given an array of n elements and we define d[i]=max(a1,a2.....,a[i])-min(a1,a2.....,a[i])
and our goal is to minimize the sum d[1]+d[2]+d[3]+.....+d[n]*/

/*Solution : the first thing is when we have both maxi and mini in the prefix i then definetly d[i]=maxi-mini and same for i+1....
so we make either maxi or mini as last element or first element (for that we can sort that array beacuse every time we need to do that)
so for dp[n]=maxi-mini;
and now for dp[n-1] we  need to reduce so we can either remove mini or maxi but we don't know which yeilds minimum so we take min
of them for every time
so dp[l][r]=a[r]-a[l]+min(dp[l+1][r],dp[l][r-1])
*/
const ll N = (ll)(2 * 1e3 + 5);
ll n;
ll a[N];
ll dp[N][N];
ll compute(ll l, ll r)
{
	if (l == r) return 0;
	if (dp[l][r] != -1)return dp[l][r];
	return dp[l][r] = a[r] - a[l] + min(compute(l + 1, r), compute(l, r - 1));
}
void solve()
{

	cin >> n;
	fr(i, 0, n)cin >> a[i];
	sort(a, a + n);
	memset(dp, -1, sizeof(dp));
	cout << compute(0, n - 1) << '\n';
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