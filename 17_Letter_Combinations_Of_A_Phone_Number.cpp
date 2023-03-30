/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]


Constraints:
0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
      void generateLetterCombinations(string &current, int index, string &digits, vector<string> &charMap, vector<string> &ans)
      {
            if (index == digits.length())
            {
                  ans.push_back(current);
                  return;
            }
            int digit = digits[index] - '0';
            for (int i = 0; i < charMap[digit].size(); ++i)
            {
                  current.push_back(charMap[digit][i]);
                  generateLetterCombinations(current, index + 1, digits, charMap, ans);
                  current.pop_back();
            }
      }

public:
      vector<string> letterCombinations(string digits)
      {
            vector<string> charMap(10);
            charMap[0] = "0";
            charMap[1] = "1";
            charMap[2] = "abc";
            charMap[3] = "def";
            charMap[4] = "ghi";
            charMap[5] = "jkl";
            charMap[6] = "mno";
            charMap[7] = "pqrs";
            charMap[8] = "tuv";
            charMap[9] = "wxyz";

            vector<string> ans;
            if (digits.length() == 0)
                  return ans;
            string current = "";
            generateLetterCombinations(current, 0, digits, charMap, ans);
            return ans;
      }
};

int main()
{
      string digits = "23";
      Solution obj;
      vector<string> ans = obj.letterCombinations(digits);
      for (int i = 0; i < ans.size(); ++i)
      {
            cout << ans[i] << " ";
      }
      return 0;
}