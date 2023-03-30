/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Constraints:
    1 <= s.length <= 10^4
    s consists of parentheses only '()[]{}'.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Given s w/ '(, ), {, }, [, ]', determine if valid
    Ex. s = "()[]{}" -> true, s = "(]" -> false

    Stack of opens, check for matching closes & validity

    Time: O(n)
    Space: O(n)
*/
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> open;

        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if (open.empty())
                    return false;
                if (s[i] == ')' && open.top() != '(')
                    return false;
                if (s[i] == '}' && open.top() != '{')
                    return false;
                if (s[i] == ']' && open.top() != '[')
                    return false;
                open.pop();
            }
            else
            {
                open.push(s[i]);
            }
        }

        if (!open.empty())
            return false;
        return true;
    }
};

int main()
{
    string s = "()[]{}";

    Solution obj;
    auto ans = obj.isValid(s);
    cout << ans << "\n";

    return 0;
}