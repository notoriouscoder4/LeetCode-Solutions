/*
A valid IP address consists of exactly four integers separated by single dots.
Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses,
but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.

Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s.
You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

Example 1:
Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]

Example 2:
Input: s = "0000"
Output: ["0.0.0.0"]

Example 3:
Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]

Constraints:
    1 <= s.length <= 20
    s consists of digits only.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> ans;

    bool isValid(string s)
    {
        if ((s[0] == '0' && s.size() > 1) || s.size() == 0)
            return false;
        if (s[0] == '0' && s.size() == 1)
            return true;

        int num = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            int n = s[i] - '0';   // char num to int
            num *= 10;            // '255' -> 2, 2*10+5, 25*10+5
            if (n >= 0 && n <= 9) // this means n is part of the digit and not any special character
                num += n;
            else
                return false;
        }
        if (num >= 0 && num <= 255)
            return true;
        return false;
    }

    void backtrack(string s, int i, vector<string> segment, int j)
    {
        if (i == s.size())
        {
            if (segment.size() == 4)
            {
                string temp;
                for (int k = 0; k < 4; ++k)
                {
                    temp += segment[k];
                    if (k != 3)
                        temp += '.';
                }
                ans.push_back(temp);
            }
            return;
        }

        string originalSegment, newSegment;
        originalSegment = segment[j];
        newSegment = s[i];

        if (isValid(originalSegment + s[i]))
        {
            segment[j] += s[i];
            backtrack(s, i + 1, segment, j);
            segment[j] = originalSegment;
        }
        if (originalSegment.size() > 0 && isValid(newSegment) && segment.size() < 4)
        {
            segment.push_back(newSegment);
            backtrack(s, i + 1, segment, j + 1);
            segment.pop_back();
        }
        return;
    }

    vector<string> restoreIpAddresses(string s)
    {
        vector<string> temp;
        temp.push_back("");
        
        backtrack(s, 0, temp, 0);

        return ans;
    }
};

int main()
{
    string s = "101023";

    Solution obj;
    auto ans = obj.restoreIpAddresses(s);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";

    return 0;
}