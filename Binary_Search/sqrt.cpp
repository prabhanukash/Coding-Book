#include<bits/stdc++.h>
using namespace std;
class Solution
{
private:
	bool good(int n, long long val)
	{
		long long sqrt = val * val;
		return sqrt <= n;
	}

public:
	int mySqrt(int x)
	{
		if (x <= 1)
			return x;
		int l = 0;
		int r = x;
		while (r > l + 1)
		{
			long long m = (l + r) >> 1;
			if (good(x, m))
			{
				l = m;
			}
			else
			{
				r = m;
			}
		}
		return l;
	}
};

int main(){
	Solution solution;
	int n;
	cin >> n;
	int ans = solution.mySqrt(n);
	cout << ans;
}