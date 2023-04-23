/*
A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"

To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways).
For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)

Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.

Example 1:
Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).

Example 2:
Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

Example 3:
Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").

Constraints:
    1 <= s.length <= 100
    s contains only digits and may contain leading zero(s).
*/

#include <bits/stdc++.h>
using namespace std;

/*
For a character s[i], we have 2 ways to decode:
    1. Single digit: Require s[i] != '0' (decoded to 1..9)
    2. Two digits: Require i + 1 < len(s) and (s[i] == 1 (decoded to 10..19) or s[i] == 2 and s[i+1] <= '6') (decoded to 20..26).
*/

/*
Complexity
    Time: O(N), where N <= 100 is length of string s.
    Space: O(N)
*/
class Solution_Memoization
{
public:
    int t[100] = {};
    int memoization(const string &s, int i)
    {
        if (i == s.size())
            return 1;
        if (t[i] != 0)
            return t[i];

        int ans = 0;

        if (s[i] != '0') // Single digit
            ans += memoization(s, i + 1);
        if (i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6')) // Two digits
            ans += memoization(s, i + 2);

        return t[i] = ans;
    }

    int numDecodings(string s)
    {
        return memoization(s, 0);
    }
};

/*
Complexity
    Time: O(N), where N <= 100 is length of string s.
    Space: O(N)
*/
class Solution_Tabulation
{
public:
    int numDecodings(const string &s)
    {
        int n = s.size();
        vector<int> t(n + 1, 0);
        t[n] = 1;

        for (int i = n - 1; i >= 0; --i)
        {
            if (s[i] != '0') // Single digit
                t[i] += t[i + 1];
            if (i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6')) // Two digits
                t[i] += t[i + 2];
        }

        return t[0];
    }
};

/*
Since our dp only need to keep up to 3 following states:
    1. Current state, let name dp corresponding to dp[i]
    2. Last state, let name dp1 corresponding to dp[i+1]
    3. Last twice state, let name dp2 corresponding to dp[i+2]

So we can achieve O(1) in space.
*/
class Solution_Tabulation
{
public:
    int numDecodings(const string &s)
    {
        int n = s.size();
        int t = 0, t1 = 1, t2 = 0;

        for (int i = n - 1; i >= 0; --i)
        {
            if (s[i] != '0') // Single digit
                t += t1;
            if (i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6')) // Two digits
                t += t2;

            t2 = t1;
            t1 = t;
            t = 0;
        }

        return t1;
    }
};
