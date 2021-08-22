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
vi computeZ(string str)
{
	ll len = str.S;
	vi Z(len);
	Z[0] = 0;
	ll l = 0, r = 0;
	for (ll k = 1; k < len; k++)
	{
		if (k > r)
		{
			l = r = k;
			while (str[r] == str[r - l] and r < len)r++;
			Z[k] = r - l;
			r--;
		}
		else
		{
			ll k1 = k - l;
			if (Z[k1] < r - l + 1)Z[k] = Z[k1];
			else
			{
				l = k;
				while (str[r] == str[r - l] and r < len)r++;
				Z[k] = r - l;
				r--;
			}
		}
	}
	return Z;
}
vi patternMatching(string txt , string pat) {
	ll n = txt.S;
	ll m = pat.S;
	string str = "";
	str += pat;
	str += '$';
	str += txt;
	//cout << str << '\n';
	vi Z = computeZ(str);
	vi res;
	for (int i = 0; i < Z.S; i++)
	{
		//cout << Z[i] << ' ';
		if (Z[i] == m)
		{
			res.pb(i - m - 1);
		}
	}
	return res;
}
void solve()
{
	string txt;
	string pat;
	getline(cin, txt);
	getline(cin, pat);
	vi res = patternMatching(txt, pat);
	for (auto it : res)cout << it << ' ';
	cout << '\n';
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