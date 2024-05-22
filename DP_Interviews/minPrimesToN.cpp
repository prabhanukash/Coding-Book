#include <bits/stdc++.h>
using namespace std;

vector<int> primes;

void seive(int N){
    vector<bool> prime(N + 1, true);

    for (int p = 2; p * p <= N; p++)
    {
        if(prime[p] == true){
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= N; p++)
        if (prime[p])primes.push_back(p);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int N, M;
    cin >> N >> M;
    seive(M);
    vector<int> dp(N + 1, INT_MAX);
    dp[0] = 0;
    for (int amt = 1; amt <= N;amt++){
        for(int coin:primes){
            if(coin<=amt){
                dp[amt] = min(dp[amt], 1 + dp[amt - coin]);
            }
        }
    }
    if(dp[M]!=1e9)
        cout << dp[M] << '\n';
    else
        cout << "-1\n";
        return 0;
}