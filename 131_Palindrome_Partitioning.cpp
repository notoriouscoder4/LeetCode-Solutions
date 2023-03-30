/*

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> ans;

    bool isPalindrome(string s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    void solve(string s, int index, vector<string> &temp)
    {
        if (index == s.size())
        {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < s.size(); ++i)
        {
            if (isPalindrome(s, index, i))
            {
                temp.push_back(s.substr(index, i - index + 1));
                solve(s, i + 1, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<string> temp;

        solve(s, 0, temp);
        return ans;
    }
};