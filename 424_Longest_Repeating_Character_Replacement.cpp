/*
You are given a string s and an integer k.
You can choose any character of the string and change it to any other uppercase English character.
You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.

Constraints:
    1 <= s.length <= 10^5
    s consists of only uppercase English letters.
    0 <= k <= s.length
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Given a string s & an int k, can change any char k times:
    Return length of longest substring containing same letter
    Ex. s = "ABAB" k = 2 -> 4 "AAAA", s = "AABABBA" k = 1 -> 4

    Sliding window, expand if can change char, contract if > k

    Time: O(n)
    Space: O(26)
*/
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> count(26);
        int max_count = 0;

        int i = 0;
        int j = 0;

        int max_length = 0;

        while (j < s.size())
        {
            count[s[j] - 'A']++;
            max_count = max(max_count, count[s[j] - 'A']);

            if (j - i + 1 - max_count > k)
            {
                count[s[i] - 'A']--;
                i++;
            }
            max_length = max(max_length, j - i + 1);
            j++;
        }
        return max_length;
    }
};

int main()
{
    string s = "AABABBA";
    int k = 1;

    Solution obj;
    auto ans = obj.characterReplacement(s, k);

    cout << "the length of the longest substring after performing k operations: " << ans << "\n";

    return 0;
}