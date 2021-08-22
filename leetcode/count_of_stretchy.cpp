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
ll getConsecutiveLen(string &s, ll start)
{
	ll end = start;
	while (end < s.S and s[end] == s[start])end++;
	return (end - start);
}
bool is_stretchy(string s, string str)
{
	ll i = 0, j = 0;
	while (i < s.S && j < str.S)
	{
		if (s[i] != str[j])return false;
		ll consecutiveS = getConsecutiveLen(s, i);
		ll consecutiveStr = getConsecutiveLen(str, j);
		if ((consecutiveS > consecutiveStr or consecutiveStr < 3) and consecutiveStr != consecutiveS) return false;
		i += consecutiveS;
		j += consecutiveStr;
	}

	return (i == s.S && j == str.S);

}
ll count_of_stretchy(string s, vs &words)
{
	ll cnt = 0;
	for (string &str : words)
	{
		if (is_stretchy(s, str))cnt++;
	}
	return cnt;
}
void solve()
{
	string s;
	vs words;
	ll n;
	cin >> n;
	fr(i, 0, n)
	{
		string str;
		cin >> str;
		words.pb(str);
	}
	cout <<	count_of_stretchy(s, words) << '\n';
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