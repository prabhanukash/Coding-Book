#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
#define ff first
#define ss second
#define S size()
#define mod (ll)(1e9 + 9)
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
const ll N = (ll)(1 * 1e5 + 5);
// calculating the hash value with the equation
// 	==> s[0]*p^0 + s[1]*p^1 + s[2]*p^2 + s[3]*p^3 + ......s[n-1]*p^n-1
// ==> for first m characters the hash function will lool like this
//		==>h1=s[0]*p^0 + s[1]*p^1 + s[2]*p^2 + s[3]*p^3 + ......s[m-1]*p^m-1
//     for next m characters the hash function will lool like this
//		==>h2=s[1]*p^0 + s[2]*p^1 + s[3]*p^2 + s[4]*p^3 + ......s[m-1]*p^m-2 + s[m]*p^m-1
// then we rewrite the h1 we get (h1-s[0])/p +s[m]*p^m-1=h2
ll  value(char ch)
{
	return (int)ch;
}
ll rabinKarp(string A, string B)
{
	ll n = A.S;
	ll m = B.S;
	ll powers[N];
	powers[0] = 1;
	ll p = 31;
	ll pinv = 838709685;
	for (ll i = 1; i <= m - 1; i++)
	{
		powers[i] = (powers[i - 1] * p) % mod;
	}
	ll hashA = 0;
	ll hashB = 0;
	fr(i, 0, m)// first window
	{
		hashA = (hashA + (value(A[i]) * powers[i])) % mod;
		hashB = (hashB + (value(B[i]) * powers[i])) % mod;
	}
	ll cnt = 0;
	for (ll i = 0; i <= n - m; i++) {
		if (hashA == hashB)cnt++;
		if (i < n - m)
		{
			hashA = (hashA - value(A[i]) + mod) * pinv % mod;
			hashA = (hashA + value(A[i + m]) * powers[m - 1]) % mod;
		}
	}
	return cnt;
}

void solve()
{
	string A;
	getline(cin, A);// for taking the sentence
	//cout << A << '\n';
	ll q;
	cin >> q;
	//cout << q << '\n';
	while (q--)
	{
		string B;
		cin >> B;
		cout << rabinKarp(A, B) << '\n';
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
		solve();
	}
}