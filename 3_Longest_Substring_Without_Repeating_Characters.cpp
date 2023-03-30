/*
Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:
    0 <= s.length <= 5 * 10^4
    s consists of English letters, digits, symbols and spaces.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Given string, find longest substring w/o repeating chars
    Ex. s = "abcabcbb" -> 3 "abc", s = "bbbbb" -> 1 "b"

    Sliding window, expand if unique, contract if duplicate

    Time: O(n)
    Space: O(n)
*/
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> mp; // <key, value> = <char, count_of_character>
        int i = 0, j = 0;
        int max_length = 0;

        while (j < s.length())
        {
            mp[s[j]]++;
            if (mp.size() == j - i + 1) // j-i+1 = window size
            {
                max_length = max(max_length, j - i + 1);
                j++;
            }
            else if (mp.size() < j - i + 1) // it means window does not have unique characters
            {
                while (mp.size() < j - i + 1)
                {
                    mp[s[i]]--;
                    if (mp[s[i]] == 0) // if count of any character in the map becomes zero then remove that character from map
                        mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }

        return max_length;
    }
};

int main()
{
    string s = "abcabcbb";
    Solution obj;

    auto ans = obj.lengthOfLongestSubstring(s);
    cout << "the length of the longest substring without repeating characters: " << ans << "\n";

    return 0;
}