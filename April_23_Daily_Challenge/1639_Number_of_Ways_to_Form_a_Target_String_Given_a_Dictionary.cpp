/*
You are given a list of strings of the same length words and a string target.

Your task is to form target using the given words under the following rules:

    1. target should be formed from left to right.
    2. To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
    3. Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k.
    In other words, all characters to the left of or at index k become unusuable for every string.
    4. Repeat the process until you form the string target.

Notice that you can use multiple characters from the same string in words provided the conditions above are met.

Return the number of ways to form target from words. Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:
Input: words = ["acca","bbbb","caca"], target = "aba"
Output: 6
Explanation: There are 6 ways to form target.
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")

Example 2:
Input: words = ["abba","baab"], target = "bab"
Output: 4
Explanation: There are 4 ways to form target.
"bab" -> index 0 ("baab"), index 1 ("baab"), index 2 ("abba")
"bab" -> index 0 ("baab"), index 1 ("baab"), index 3 ("baab")
"bab" -> index 0 ("baab"), index 2 ("baab"), index 3 ("baab")
"bab" -> index 1 ("abba"), index 2 ("baab"), index 3 ("baab")

Constraints:
    1 <= words.length <= 1000
    1 <= words[i].length <= 1000
    All strings in words have the same length.
    1 <= target.length <= 1000
    words[i] and target contain only lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numWays(vector<string> &words, string target)
    {
        int n = words[0].size();
        int m = target.size();
        int mod = 1e9 + 7;
        vector<int> t(m + 1, 0);
        t[0] = 1;

        vector<vector<int>> count(n, vector<int>(26, 0));
        for (const string &word : words)
        {
            for (int i = 0; i < n; i++)
            {
                count[i][word[i] - 'a']++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                t[j + 1] += (int)((long)t[j] * count[i][target[j] - 'a'] % mod);
                t[j + 1] %= mod;
            }
        }
        return t[m];
    }
};