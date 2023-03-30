/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

    1. Insert a character
    2. Delete a character
    3. Replace a character

Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

Constraints:
    0 <= word1.length, word2.length <= 500
    word1 and word2 consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int t[501][501];
    int editDistance(string s1, string s2, int i, int j)
    {
        if (i == -1 && j == -1)
            return 0;
        if (i == -1)
            return j + 1; // (j+1) insertions
        if (j == -1)
            return i + 1; // (i+1) deletion
        if (t[i][j] != -1)
            return t[i][j];
        if (s1[i] == s2[j])
            return t[i][j] = editDistance(s1, s2, i - 1, j - 1);

        int ins = 1 + editDistance(s1, s2, i, j - 1);
        int rep = 1 + editDistance(s1, s2, i - 1, j - 1);
        int del = 1 + editDistance(s1, s2, i - 1, j);
        return t[i][j] = min(ins, min(rep, del));
    }

    int minDistance(string word1, string word2)
    {
        memset(t, -1, sizeof(t));
        return editDistance(word1, word2, word1.length() - 1, word2.length() - 1);
    }
};