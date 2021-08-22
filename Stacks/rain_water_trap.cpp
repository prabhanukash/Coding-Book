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
const ll LOGN = 25;
char a[1000][1000];
ll appraoch_2(ll arr[], ll n)
{
	ll low = 0, high = n - 1;
	ll left_max = 0, right_max = 0;
	ll ans = 0;
	while (low <= high) {
		if (arr[low] < arr[high]) {
			if (arr[low] > left_max)
				// update max in left
				left_max = arr[low];
			else
				// water on curr element = max - curr
				ans += left_max - arr[low];
			low++;
		}
		else {
			if (arr[high] > right_max)
				// update right maximum
				right_max = arr[high];
			else
				ans += right_max - arr[high];
			high--;
		}
	}
	return ans;

}
void solve()
{
	ll n;
	cin >> n;
	ll a[n];
	fr(i, 0, n)cin >> a[i];
	cout << appraoch_2(a, n) << '\n';
	/*ll pref_max[n], suff_max[n];
	pref_max[0] = a[0];
	ff_max[n - 1] = a[n - 1];
	/*fr(i, 1, n)
	{
		pref_max[i] = max(pref_max[i - 1], a[i]);
	}
	for (ll i = n - 2; i >= 0; i--)
	{
		suff_max[i] = max(suff_max[i + 1], a[i]);
	}
	/*fr(i, 0, n)cout << suff_max[i] << ' ';
	cout << '\n';
	fr(i, 0, n)cout << pref_max[i] << ' ';
	ll ans = 0;
	fr(i, 0, n)
	{
		ans += min(pref_max[i], suff_max[i]) - a[i];
	}
	cout << ans << '\n'; */
}
signed main()
{
	fast();
#ifndef ONLINE_JUDGE
	freopen ("inp.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif
	ll t = 1;
	//cin >> t;
	fr(i, 0, t)
	{
		solve();
	}
}