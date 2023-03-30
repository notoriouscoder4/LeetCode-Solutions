/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words.
The returned string should only have a single space separating the words. Do not include any extra spaces.

Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

Constraints:
    1 <= s.length <= 10^4
    s contains English letters (upper-case and lower-case), digits, and spaces ' '.
    There is at least one word in s.

Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        // Breaking input into word using string stream
        // Used for breaking words
        stringstream str(s);
        string word;

        // to store words
        vector<string> temp;
        // to store the ans.
        string ans = "";

        while (str >> word) // operator >> - Read something from the stringstream object.
            temp.push_back(word);

        // now store the words in reverse order and add the extra space at the end of each word. except the first one.
        for (int i = temp.size() - 1; i >= 0; --i)
        {
            if (i != 0) // it means that word in temp is not last word to be stored in ans and we can add space after that word.
                ans += temp[i] + " ";
            else // it means that word in temp is last and we cannot add space.
                ans += temp[i];
        }
        return ans;
    }
};

int main()
{
    string s = "  hello world  ";

    Solution obj;
    auto ans = obj.reverseWords(s);
    cout << ans << "\n";

    return 0;
}