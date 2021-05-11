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
void upheapify(vi &a, ll idx)
{

	if (idx == 0)return;
	ll pidx = (idx - 1) / 2;
	if (a[pidx] < a[idx])swap(a[pidx], a[idx]), upheapify(a, pidx);
	else return;
}
void downheapify(vi &a, ll idx)
{
	ll lc = 2 * idx + 1;
	ll rc = 2 * idx + 2;
	if (lc >= (ll)a.S and rc >= (ll)a.S)return;
	ll largest = idx;
	if (lc < (ll)a.S and a[lc]>a[largest])largest = lc;
	if (rc < (ll)a.S and a[rc] > a[largest])largest = rc;
	if (largest == idx)return;
	swap(a[largest], a[idx]);
	downheapify(a, largest);
}
void build(vi &a)
{
	ll i = (ll)a.S - 1;
	i = (i / 2) + 1;
	while (i >= 0)
	{
		downheapify(a, i);
		i--;
	}
	return;
}
void insert(vi & a, ll key)
{
	a.pb(key); upheapify(a, (ll)a.S - 1);
}
ll get(vi & a)
{
	return a[0];
}
void removePeek(vi & a)
{
	if (a.S == 0)
	{
		cout << -1 << '\n';
		return;
	}
	ll i = (ll)a.S - 1;
	swap(a[0], a[i]);
	a.pop_back();
	downheapify(a, 0);
}
void downheapifyHeapSortHelper(vi &a, ll idx, ll heapSize)
{
	ll lc = 2 * idx + 1;
	ll rc = 2 * idx + 2;
	if (lc >= (ll)a.S and rc >= (ll)a.S)return;
	ll largest = idx;
	if (lc < (ll)a.S and a[lc]>a[largest])largest = lc;
	if (rc < (ll)a.S and a[rc] > a[largest])largest = rc;
	if (largest == idx)return;
	swap(a[largest], a[idx]);
	downheapify(a, largest);
}
void HeapSort(vi&a)
{

}
void solve()
{
	ll n;
	cin >> n;
	vi a;
	fr(i, 0, n)
	{
		ll x;
		cin >> x;
		a.pb(x);
	}
	build(a);
	fr(i, 0, a.S)cout << a[i] << ' ';
	cout << '\n';
	cout << get(a) << '\n';
	removePeek(a);
	cout << get(a) << '\n';
	fr(i, 0, a.S)cout << a[i] << ' ';
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