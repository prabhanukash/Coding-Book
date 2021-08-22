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

void solve()
{
// basically we will be given a string and we need to find the longest palindromic substring
	string s;
	cin >> s;
	ll n = s.S;
	ll oc[n], ec[n + 1];
	for (ll i = 0, c = 0, dis = -1; i < n; i++) // we will make each i as the center of the palindrome and try to get what max palindrome can get from left right
	{
		if (i > c + dist)oc[i] = 1;// i is beyond the curr largest palindrome's right boundary then it will equalto 1
		else if (i + oc[2 * c - i] - 1 >= c + dist)oc[i] = c + dist - i + 1;// if the palindrome at index i’ expands beyond the left boundary (l) of the current longest palindrome, we can say that the minimum certainly possible expansion length at i is r-i
		else oc[i] = oc[2 * c - i];
		while (i - oc[i] >= 0 and i + oc[i] < n and s[i + oc[i]] == s[i + oc[i]])oc[i]++;
		//check if the expanded palindrome at i is expanding beyond the right boundary of current longest palindrome at center c
		//if it is, the new center is i
		if (i + oc[i] - 1 > c + dis)
		{
			c = i;
			dis = oc[i] - 1;
		}
	}
	for (ll i = 0, c = 0, dis = -1; i <= n; i++) // we will make each i as the center of the palindrome and try to get what max palindrome can get from left right
	{
		if (i > c + dist)ec[i] = 0;
		else if (i + ec[2 * c - i] - 1 >= c + dist)ec[i] = c + dist - i + 1;
		else ec[i] = ec[2 * c - i];
		while (i - ec[i] >= 0 and i + ec[i] < n and s[i + ec[i]] == s[i + ec[i]])ec[i]++;
		if (i + ec[i] - 1 > c + dis)
		{
			c = i;
			dis = ec[i];
		}
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
