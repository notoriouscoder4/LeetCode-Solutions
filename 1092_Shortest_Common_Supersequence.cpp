/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.
If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

Example 1:
Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation:
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.

Example 2:
Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"

Constraints:
    1 <= str1.length, str2.length <= 1000
    str1 and str2 consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution_Tabulation
{
public:
    string lcs(string a, string b, int n, int m)
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
                if (a[i - 1] == b[j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];
                else
                    t[i][j] = max(t[i][j - 1], t[i - 1][j]);
            }
        }

        int i = n, j = m;
        string s = "";

        while (i > 0 && j > 0)
        {
            if (a[i - 1] == b[j - 1])
            {
                s.push_back(a[i - 1]);
                i--, j--;
            }
            else
            {
                if (t[i][j - 1] > t[i - 1][j])
                {
                    s.push_back(b[j - 1]);
                    j--;
                }
                else
                {
                    s.push_back(a[i - 1]);
                    i--;
                }
            }
        }

        while (i > 0)
        {
            s.push_back(a[i - 1]);
            i--;
        }

        while (j > 0)
        {
            s.push_back(b[j - 1]);
            j--;
        }

        reverse(s.begin(), s.end());
        return s;
    }

    string shortestCommonSupersequence(string str1, string str2)
    {
        return lcs(str1, str2, str1.size(), str2.size());
    }
};

int main()
{
    string a = "abac";
    string b = "cab";

    Solution_Tabulation obj;
    auto ans = obj.shortestCommonSupersequence(a, b);
    cout << ans << "\n";

    return 0;
}