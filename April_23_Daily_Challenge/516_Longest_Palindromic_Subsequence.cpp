/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.



Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".


Constraints:
    1 <= s.length <= 1000
    s consists only of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution_Recursive
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

    int longestPalindromeSubseq(string s)
    {
        string b = s;
        reverse(b.begin(), b.end());
        return lcs(s, b, s.length(), b.length());
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

    int longestPalindromeSubseq(string s)
    {
        memset(t, -1, sizeof(t));
        string b = s;
        reverse(b.begin(), b.end());
        return lcs(s, b, s.length(), b.length());
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

    int longestPalindromeSubseq(string s)
    {
        string b = s;
        reverse(b.begin(), b.end());
        return lcs(s, b, s.length(), b.length());
    }
};

int main()
{
    string s = "bbbab";

    Solution_Tabulation obj;
    auto ans = obj.longestPalindromeSubseq(s);
    cout << ans << "\n";

    return 0;
}