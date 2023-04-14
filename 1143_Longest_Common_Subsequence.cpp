/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.


Example 1:
Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

Constraints:
    1 <= text1.length, text2.length <= 1000
    text1 and text2 consist of only lowercase English characters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution_Recursion
{
public:
    int lcs(string x, string y, int n, int m)
    {
        if (n == 0 || m == 0)
            return 0;

        if (x[n - 1] == y[m - 1])
            return 1 + lcs(x, y, n - 1, m - 1);
        else
            return max(lcs(x, y, n, m - 1), lcs(x, y, n - 1, m));
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        return lcs(text1, text2, text1.length(), text2.length());
    }
};

class Solution_Memoization
{
public:
    int t[1001][1001];
    int lcs(string x, string y, int n, int m)
    {
        if (n == 0 || m == 0)
            return 0;

        if (t[n][m] != -1)
            return t[n][m];

        if (x[n - 1] == y[m - 1])
            t[n][m] = 1 + lcs(x, y, n - 1, m - 1);
        else
            t[n][m] = max(lcs(x, y, n, m - 1), lcs(x, y, n - 1, m));
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        memset(t, -1, sizeof(t));
        return lcs(text1, text2, text1.length(), text2.length());
    }
};

class Solution_Tabulation
{
public:
    int lcs(string x, string y, int n, int m)
    {
        int t[n + 1][m + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < m + 1; j++)
            {
                if (i == 0 || j == 0)
                    t[i][j] = 0;
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                if (x[i - 1] == y[j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];
                else
                    t[i][j] = max(t[i][j - 1], t[i - 1][j]);
            }
        }
        return t[n][m];
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        return lcs(text1, text2, text1.length(), text2.length());
    }
};

int main()
{
    string s1 = "abcde";
    string s2 = "ace";

    Solution_Tabulation obj;
    auto ans = obj.longestCommonSubsequence(s1, s2);
    cout << ans << "\n";

    return 0;
}