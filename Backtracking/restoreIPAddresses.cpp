#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isValidNumber(string s)
    {
        return stoi(s) >= 0 and stoi(s) <= 255 and to_string(stoi(s)) == s;
    }
    void f(string ip, int idx, string osf, int count, vector<string> &ans)
    {
        if (count > 4)
            return;
        if (count == 4 and idx == ip.size())
        {
            ans.push_back(osf);
            return;
        }
        for (int i = 1; i < 4; i++)
        {
            if (idx + i > ip.size())
                continue;
            string nextPossibleNum = ip.substr(idx, i);
            if (isValidNumber(nextPossibleNum) == false)
                break;
            f(ip, idx + i, osf + nextPossibleNum + ((count == 3) ? "" : "."), count + 1, ans);
        }
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ans;
        f(s, 0, "", 0, ans);
        return ans;
    }
};
int main()
{
    Solution solution;
    string s;
    cin >> s;
    vector<string> ans = solution.restoreIpAddresses(s);
    for (string str : ans)
        cout << str << endl;

    return 0;
}
