/*
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

Example 1:
Input: s = "abbaca"
Output: "ca"
Explanation:
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.
The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

Example 2:
Input: s = "azxxzy"
Output: "ay"


Constraints:
    1 <= s.length <= 10^5
    s consists of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    TC: O(N), SC: O(N)
*/
class Solution_stack
{
public:
    string removeDuplicates(string s)
    {
        int n = s.size();
        // declare a stack
        stack<char> st;

        // iterate over the string
        for (int i = 0; i < n; i++)
        {
            // flag will keep track of that we have to push the curr char into stack or not
            bool flag = true;

            // if the curr char == st.top(), then remove the top char and mark flag as false
            if (st.empty() == false && st.top() == s[i])
            {
                flag = false;
                st.pop();
            }

            // if flag is true, push the curr char into stack
            if (flag)
            {
                st.push(s[i]);
            }
        }

        // finally form the res string
        string res = "";

        // pop out all the elements from the stack
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }

        // reverse the res
        reverse(res.begin(), res.end());

        return res;
    }
};

/*
    TC: O(N), SC: O(1)
*/
class Solution
{
public:
    string removeDuplicates(string s)
    {
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (ans == "")
                ans.push_back(s[i]);
            else if (ans.back() == s[i])
                ans.pop_back();
            else
                ans.push_back(s[i]);
        }
        return ans;
    }
};