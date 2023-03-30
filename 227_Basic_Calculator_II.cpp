/*
Given a string s which represents an expression, evaluate this expression and return its value.

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Example 1:
Input: s = "3+2*2"
Output: 7

Example 2:
Input: s = " 3/2 "
Output: 1

Example 3:
Input: s = " 3+5 / 2 "
Output: 5

Constraints:
    1 <= s.length <= 3 * 10^5
    s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
    s represents a valid expression.
    All the integers in the expression are non-negative integers in the range [0, 231 - 1].
    The answer is guaranteed to fit in a 32-bit integer.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Algorithm

The approach works similar to Approach 1 with the following differences :

1. Instead of using a stack, we use a variable lastNumber to track the value of the last evaluated expression.
2. If the operation is Addition (+) or Subtraction (-), add the lastNumber to the result instead of pushing it to the stack.
The currentNumber would be updated to lastNumber for the next iteration.
3. If the operation is Multiplication (*) or Division (/),
we must evaluate the expression lastNumber * currentNumber and update the lastNumber with the result of the expression.
This would be added to the result after the entire string is scanned.

Complexity Analysis

Time Complexity: O(n), where n is the length of the string s.

Space Complexity: O(1), as we use constant extra space to store lastNumber, result and so on.
*/
class Solution
{
public:
    int calculate(string s)
    {
        int length = s.length();
        if (length == 0)
            return 0;

        int current_number = 0, last_number = 0, result = 0;
        char sign = '+';

        for (int i = 0; i < length; ++i)
        {
            char current_char = s[i];
            if (isdigit(current_char))
            {
                current_number = (current_number * 10) + (current_char - '0');
            }
            if (!isdigit(current_char) && !iswspace(current_char) || i == length - 1)
            {
                if (sign == '+' || sign == '-')
                {
                    result += last_number;
                    last_number = (sign == '+') ? current_number : -current_number;
                }
                else if (sign == '*')
                {
                    last_number = last_number * current_number;
                }
                else if (sign == '/')
                {
                    last_number = last_number / current_number;
                }
                sign = current_char;
                current_number = 0;
            }
        }

        result += last_number;
        return result;
    }
};

int main()
{
    string s = "3+2*2";

    Solution obj;
    auto ans = obj.calculate(s);
    cout << ans << "\n";

    return 0;
}