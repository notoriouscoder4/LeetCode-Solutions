/*
Given a string s, partition the string into one or more substrings such that the characters in each substring are unique.
That is, no letter appears in a single substring more than once.

Return the minimum number of substrings in such a partition.

Note that each character should belong to exactly one substring in a partition.

Example 1:
Input: s = "abacaba"
Output: 4
Explanation:
Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
It can be shown that 4 is the minimum number of substrings needed.

Example 2:
Input: s = "ssssss"
Output: 6
Explanation:
The only valid partition is ("s","s","s","s","s","s").

Constraints:
    1 <= s.length <= 10^5
    s consists of only English lowercase letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int partitionString(string s)
    {
        unordered_set<char> st;
        int count = 1;
        for (int i = 0; i < s.size(); i++)
        {
            if (st.find(s[i]) != st.end())
            {
                count++;
                st.clear();
            }
            st.insert(s[i]);
        }
        return count;
    }

    int partitionString_method2(string s)
    {
        int last_pos[26] = {}, partitions = 0, last_end = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (last_pos[s[i] - 'a'] >= last_end)
            {
                partitions++;
                last_end = i + 1;
            }
            last_pos[s[i] - 'a'] = i + 1;
        }
        return partitions;
    }

    int partitionString_BIT_MASKING(string s)
    {
        int i = 0, ans = 1, mask = 0;
        while (i < s.size())
        {
            int val = s[i] - 'a';
            if (mask & (1 << val))
            {
                mask = 0;
                ans++;
            }
            mask = mask | (1 << val);
            i++;
        }
        return ans;
    }
};

int main()
{
    string s = "abacaba";

    Solution obj;
    auto ans = obj.partitionString(s);
    cout << ans << "\n";

    return 0;
}