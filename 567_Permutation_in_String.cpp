/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false

Constraints:
    1 <= s1.length, s2.length <= 10^4
    s1 and s2 consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Given 2 strings, return true if s2 contains permutation of s1
    Ex. s1 = "ab", s2 = "eidbaooo" -> true, s2 contains "ba"

    Sliding window, expand + count down char, contract + count up char

    Time: O(n)
    Space: O(1)
*/
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char, int> mp; // use hashmap to store the frequencies of all the characters present in string s1.
        for (auto it : s1)
            mp[it]++;

        int count = mp.size(); // use the count variable to see if all the characters in the map have the same frequencies, indicating that an anagram has been found.
        int i = 0, j = 0;
        int k = s1.size(); // window size

        while (j < s2.size())
        {
            if (mp.find(s2[j]) != mp.end()) // if a character is found that already exists in the map, reduce its frequency by one.
            {
                mp[s2[j]]--;
                if (mp[s2[j]] == 0) // if the frequency of the specific character on the map is 0, it means that all occurences of that character is found inside the current window size.
                    count--;
            }

            if (j - i + 1 < k)
            {
                j++;
            }
            else if (j - i + 1 == k)
            {
                if (count == 0) // Anagram found
                    return true;
                if (mp.find(s2[i]) != mp.end()) // check if that character is present in the map while sliding the window, then increase its frequency by one, as we decreased its frequency when we first met it while crossing the window.
                {
                    mp[s2[i]]++;
                    if (mp[s2[i]] == 1)
                        count++;
                }
                i++;
                j++;
            }
        }
        return false;
    }
};

int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo";

    Solution obj;
    auto ans = obj.checkInclusion(s1, s2);
    cout << "if s2 contains a permutation of s1: " << ans << "\n";

    return 0;
}