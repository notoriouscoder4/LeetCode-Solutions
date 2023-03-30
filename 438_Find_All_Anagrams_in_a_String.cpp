/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:
Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

Constraints:
    1 <= s.length, p.length <= 3 * 10^4
    s and p consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        unordered_map<char, int> mp; // HashMap to store the frequencies of all the characters present in string 'p'.
        for (auto it : p)
            mp[it]++;

        int count = mp.size(); // count variable to check when all the characters present in the map have frequencies zero,which implies that an anagram is found.
        int i = 0, j = 0;
        int k = p.length(); // window size

        while (j < s.length())
        {
            if (mp.find(s[j]) != mp.end()) // if a character is found which is present in the map then decrease it's frequency by 1.
            {
                mp[s[j]]--;
                if (mp[s[j]] == 0) // if the frequency of a particular character in the map is zero it implies that all the occurences of that particular character is found in the current window size.
                    count--;
            }

            if (j - i + 1 < k)
            {
                j++;
            }
            else if (j - i + 1 == k)
            {
                if (count == 0)       // if the count is equal is zero it means that an anagram is found.
                    ans.push_back(i); // if an anargram is found then push the starting index of the window.

                if (mp.find(s[i]) != mp.end()) // while sliding the window check if that character is present in the map then increase it's frequency by one as we have decreased the frequency of that character when it was first encountered while traversing the window.
                {
                    mp[s[i]]++;
                    if (mp[s[i]] == 1)
                        count++;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};

int main()
{
    string s = "cbaebabacd";
    string p = "abc";

    Solution obj;
    auto ans = obj.findAnagrams(s, p);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << "\n";

    return 0;
}