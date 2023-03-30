/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]

Constraints:
1 <= n <= 8
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Given n pairs of parentheses, generate all combos of well-formed parentheses
    Ex. n = 3 -> ["((()))","(()())","(())()","()(())","()()()"], n = 1 -> ["()"]

    Backtracking, keep valid, favor trying opens, then try closes if still valid

    Time: O(2^n)
    Space: O(n)
*/

class Solution
{
public:
      void backtrack(vector<string> &ans, string current, int open, int close, int max)
      {
            if (current.length() == max * 2)
            {
                  ans.push_back(current);
                  return;
            }

            if (open < max)
                  backtrack(ans, current + "(", open + 1, close, max);
            if (close < open)
                  backtrack(ans, current + ")", open, close + 1, max);
      }

public:
      vector<string> generateParenthesis(int n)
      {
            vector<string> ans;
            backtrack(ans, "", 0, 0, n);
            return ans;
      }
};

int main()
{
      int n = 3;
      Solution obj;
      vector<string> ans = obj.generateParenthesis(n);
      for (int i = 0; i < ans.size(); i++)
      {
            cout << ans[i] << " ";
      }
      return 0;
}