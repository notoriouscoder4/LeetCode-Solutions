/*
You are given a string s, which contains stars *.

In one operation, you can:

    1. Choose a star in s.
    2. Remove the closest non-star character to its left, as well as remove the star itself.

Return the string after all stars have been removed.

Note:
    1. The input will be generated such that the operation is always possible.
    2. It can be shown that the resulting string will always be unique.

Example 1:
Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".

Example 2:
Input: s = "erase*****"
Output: ""
Explanation: The entire string is removed, so we return an empty string.

Constraints:
    1 <= s.length <= 10^5
    s consists of lowercase English letters and stars *.
    The operation above can be performed on s.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Intuition
    We can use a stack to keep track of the characters in the input string.
    Whenever we encounter a star, we can remove the topmost character from the stack.
    After processing all characters in the input string, we can convert the stack to a string and return it as the output.

Approach
    1. Create a new stack to keep track of characters encountered so far.
    2. Iterate over each character in the input string.
    3. If the current character is a star, remove the topmost character from the stack.
    4. If the current character is not a star, add it to the stack.
    5. Create a new StringBuilder to store the characters in the stack.
    6. Iterate over each character in the stack and append it to the StringBuilder.
    7. Convert the StringBuilder to a string and return it as the output.

Complexity
    Time complexity:
    O(n), where n is the length of the input string. We iterate over each character in the input string once.

    Space complexity:
    O(n), where n is the length of the input string. The space used by the stack and StringBuilder is proportional to the length of the input string.


*/
class Solution
{
public:
    string removeStars(string s)
    {
        // create a stack to store the characters
        stack<char> st;

        // iterate through each character in the input string
        for (char c : s)
        {
            // if the current character is a star and the stack is not empty, pop the topmost character
            // from the stack
            if (c == '*' && !st.empty())
            {
                st.pop();
            }
            else
            {
                // otherwise, push the current character onto the stack
                st.push(c);
            }
        }

        // create a string to store the result
        string ans;

        // pop the elements of the stack and add them to the result string
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        // reverse the result string and return it as the output
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
Approach 2: Strings

Intuition
    We can also use strings in place of a stack to handle the required operations.
    It can provide similar operations as stack when dealing with characters.

Algorithm
    1. Create an empty string variable answer that will store the string while performing the required operations.
    2. Iterate over the string s from start and for each index i of the string:
        2a. If s[i] == '*', delete the last character from answer.
        2b. Otherwise, we have a non-star character, so we append it to answer.
    3. Return answer.

Note: This approach does not work for Python as the strings are immutable in Python, so this would result in an O(n^2) time complexity.
*/

class Solution_
{
public:
    string removeStars(string s)
    {
        string answer = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*')
            {
                answer.pop_back();
            }
            else
            {
                answer.push_back(s[i]);
            }
        }
        return answer;
    }
};

int main()
{
    string s = "leet**cod*e";

    Solution obj;
    auto ans = obj.removeStars(s);
    cout << ans << "\n";

    return 0;
}