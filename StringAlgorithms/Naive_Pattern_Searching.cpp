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
ll val(char ch)
{
	return (int)ch;
}
ll Rabin_Karp(string A, string B)
{
	ll n = A.S;
	ll m = B.S;
	ll p = 31;
	ll mmi = 838709685;
	ll powers[m];
	powers[0] = 1;
	for (ll i = 1; i <= m - 1; i++)
	{
		powers[i] = (powers[i - 1] * p) % mod;
	}
	ll hashA = 0, hashB = 0;
	for (ll i = 0; i < m; i++)
	{
		hashA = (hashA + (val(A[i]) * powers[i])) % mod;
		hashB = (hashB + (val(B[i]) * powers[i])) % mod;
	}
	ll cnt = 0;
	for (ll i = 0; i <= n - m; i++)
	{
		if (hashA == hashB)cnt++;
		if (i < n - m)
		{
			hashA = ((hashA - A[i] + mod) * mmi) % mod;
			hashA = hashA + (val(A[i + m]) * powers[m - 1]) % mod;
		}
	}
	return cnt;
}
void search(string txt, string pat)
{
	ll n = txt.S;
	ll m = pat.S;
	ll ans = 0;
	for (ll i = 0; i <= n - m; i++)
	{
		ll j;
		for ( j = 0; j < m; j++)
		{
			if (txt[i + j] != pat[j])
			{
				break;
			}
		}
		if (j == m)ans++;
	}
}
void solve()
{
	string txt;
	string pat;
	cin >> txt;
	cin >> pat;
	search(text, pat);

// // Rabin karp Algorithm ==> O(N+M)


// 	string a;
// 	getline(cin, a);// for taking the sentence
// 	//cout << A << '\n';
// 	ll q;
// 	cin >> q;
// 	while (q--)
// 	{
// 		string b;
// 		cin >> b;
// 		cout << Rabin_Karp(a, b) << '\n';
// 	}
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