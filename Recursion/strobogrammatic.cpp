#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<string> compute(int n, int m)
    {
        // base cases
        if (n == 0)
            return {""};
        if (n == 1)
            return {"0", "1", "8"};

        // subproblem
        vector<string> sp = compute(n - 2, m);

        // self work
        vector<string> ans;
        for (string str : sp)
        {
            if (n != m)
                ans.push_back("0" + str + "0");
            ans.push_back("1" + str + "1");
            ans.push_back("6" + str + "9");
            ans.push_back("8" + str + "8");
            ans.push_back("9" + str + "6");
        }
        return ans;
    }

public:
    vector<string> getStroboGrammaticStrings(int n)
    {
        return compute(n, n);
    }
};

int main()
{
    Solution solution;
    vector<string> ans = solution.getStroboGrammaticStrings(n);
    for (string str : ans)
        cout << str << ' ';
    return 0;
}