/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Constraints:
    1 <= s.length, t.length <= 5 * 10^4
    s and t consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Given 2 strings, return true if anagrams (same letters diff order)
    Ex. s = "anagram" & t = "nagaram" -> true, s = "rat" & t = "car" -> false

    Count chars, strings should have same # of chars if anagram

    Time: O(n)
    Space: O(26)
*/

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        vector<int> count(26);
        for (int i = 0; i < s.size(); ++i)
            count[s[i] - 'a']++;

        for (int j = 0; j < t.size(); ++j)
        {
            count[t[j] - 'a']--;
            if (count[t[j] - 'a'] < 0)
                return false;
        }
        return true;
    }
};

int main()
{
    string s = "anagram";
    string t = "nagaram";

    Solution obj;
    cout << obj.isAnagram(s, t) << "\n";
    return 0;
}