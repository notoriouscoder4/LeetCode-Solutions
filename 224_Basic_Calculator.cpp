/*
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Example 1:
Input: s = "1 + 1"
Output: 2

Example 2:
Input: s = " 2-1 + 2 "
Output: 3

Example 3:
Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23

Constraints:
    1 <= s.length <= 3 * 10^5
    s consists of digits, '+', '-', '(', ')', and ' '.
    s represents a valid expression.
    '+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
    '-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
    There will be no two consecutive operators in the input.
    Every number and running calculation will fit in a signed 32-bit integer.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        int res = 0, sign = 1; // sign: sign of current item
        stack<int> signs;      // signs: stack of signs in front of each opening '('
        signs.push(1);

        for (int i = 0; i < s.size(); ++i)
        {
            switch (s[i])
            {
            case ' ':
                break;
            case '(':
                signs.push(signs.top() * sign), sign = 1;
                break;
            case ')':
                signs.pop();
                break;
            case '+':
                sign = 1;
                break;
            case '-':
                sign = -1;
                break;
            default: // digit
                int num = s[i] - '0';
                while (i + 1 < s.size() && isdigit(s[i + 1]))
                    num = 10 * num + (s[++i] - '0');
                res += sign * signs.top() * num;
            }
        }
        return res;
    }
};

int main()
{
    string s = "(1+(4+5+2)-3)+(6+8)";

    Solution obj;
    auto ans = obj.calculate(s);
    cout << ans << "\n";

    return 0;
}