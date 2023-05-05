/*
Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

Example 1:
Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.

Example 2:
Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.

Example 3:
Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.

Constraints:
    1 <= s.length <= 10^5
    s consists of lowercase English letters.
    1 <= k <= s.length
*/

#include <bits/stdc++.h>
using namespace std;

class Solution_sliding_window
{
public:
    int maxVowels(string s, int k)
    {
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        int countInCurrWindow = 0;

        for (int i = 0; i < k; i++)
            countInCurrWindow += vowels.count(s[i]);
        int ans = countInCurrWindow;
        for (int i = k; i < s.size(); i++)
        {
            countInCurrWindow += vowels.count(s[i]) - vowels.count(s[i - k]);
            ans = max(ans, countInCurrWindow);
        }
        return ans;
    }
};

class Solution
{
public:
    int isVowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return 1;
        return 0;
    }

    int maxVowels(string s, int k)
    {
        int max_vow = 0, cur_vow = 0;
        for (int i = 0; i < s.size(); i++)
        {
            cur_vow += isVowel(s[i]);
            if (i >= k)
            {
                cur_vow -= isVowel(s[i - k]);
            }
            max_vow = max(max_vow, cur_vow);
        }
        return max_vow;
    }
};