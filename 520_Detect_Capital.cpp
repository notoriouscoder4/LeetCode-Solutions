/*
We define the usage of capitals in a word to be right when one of the following cases holds:

1. All letters in this word are capitals, like "USA".
2. All letters in this word are not capitals, like "leetcode".
3. Only the first letter in this word is capital, like "Google".

Given a string word, return true if the usage of capitals in it is right.

Example 1:
Input: word = "USA"
Output: true

Example 2:
Input: word = "FlaG"
Output: false

Constraints:
    1 <= word.length <= 100
    word consists of lowercase and uppercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        // count the capital letters present in words.
        int count = 0;
        for (int i = 0; i < word.size(); ++i)
        {
            if (isupper(word[i]))
                count++;
        }

        if ((count == word.size()) || (count == 0) || (count == 1 && isupper(word[0])))
            return true;
        return false;
    }
};

int main()
{
    string word = "leetcode";
    Solution obj;
    auto ans = obj.detectCapitalUse(word);
    cout << ans << "\n";

    return 0;
}