/*
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).


Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Constraints:
    1 <= s.length <= 20
    1 <= p.length <= 20
    s contains only lowercase English letters.
    p contains only lowercase English letters, '.', and '*'.
    It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.length();
        int m = p.length();

        vector<vector<bool>> t(n + 1, vector<bool>(m + 1, 0));
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < m + 1; j++)
            {
                // both strings are empty and empty strings are equal
                if (i == 0 && j == 0)
                    t[i][j] = true;
                // pattern is empty but there are some characters in text, match is not possible
                else if (j == 0)
                    t[i][j] = false;
                // text is empty but there are some characters in pattern,
                // and if the character in pattern is '*' then it can match with
                // 0 or more characters
                else if (i == 0)
                {
                    if (p[j - 1] == '*')
                        t[i][j] = t[i][j - 2];
                }
                else
                {
                    // both characters are same in text and pattern OR
                    // both characters are different but one character is '.' in pattern
                    // then match is possible and we will go further to match
                    if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                        t[i][j] = t[i - 1][j - 1];

                    // it means that one character in pattern is '*' which can match with zero or more characters
                    else if (p[j - 1] == '*')
                    {
                        // here we're taking '*' as one or more characters in pattern then surely
                        // we will need to go to (j-2)th index for further match
                        t[i][j] = t[i][j - 2];

                        // here (i-1)th characters in text and (j-2)th character in pattern is matching OR
                        // (j-2)th character can be '.', then we will check how many occurences of (i-1)th character is there.
                        // We'll only move our jth character if that occurence will break in text
                        if (s[i - 1] == p[j - 2] || p[j - 2] == '.')
                            t[i][j] = t[i][j] || t[i - 1][j];
                    }
                    else
                    {
                        // here there is not match between text and pattern which will eventually return false
                        t[i][j] = false;
                    }
                }
            }
        }
        return t[n][m];
    }
};