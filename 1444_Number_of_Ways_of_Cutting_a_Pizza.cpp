/*
Given a rectangular pizza represented as a rows x cols matrix containing the following characters: 'A' (an apple) and '.' (empty cell) and given the integer k.
You have to cut the pizza into k pieces using k-1 cuts.

For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the cell boundary and cut the pizza into two pieces.
If you cut the pizza vertically, give the left part of the pizza to a person. If you cut the pizza horizontally,
give the upper part of the pizza to a person. Give the last piece of pizza to the last person.

Return the number of ways of cutting the pizza such that each piece contains at least one apple.
Since the answer can be a huge number, return this modulo 10^9 + 7.



Example 1:
Input: pizza = ["A..","AAA","..."], k = 3
Output: 3
Explanation: The figure above shows the three ways to cut the pizza. Note that pieces must contain at least one apple.

Example 2:
Input: pizza = ["A..","AA.","..."], k = 3
Output: 1

Example 3:
Input: pizza = ["A..","A..","..."], k = 1
Output: 1

Constraints:
    1 <= rows, cols <= 50
    rows == pizza.length
    cols == pizza[i].length
    1 <= k <= 10
    pizza consists of characters 'A' and '.' only.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ways(vector<string> &pizza, int k)
    {
        int m = pizza.size(), n = pizza[0].size();
        // dp[k][r][c] represents the number of ways to cut the remaining pizza into k pieces
        // starting from row r and column c
        vector<vector<vector<int>>> dp(k, vector<vector<int>>(m, vector<int>(n, -1)));
        // prefSum[r][c] is the total number of apples in pizza[r:][c:]
        vector<vector<int>> prefSum(m + 1, vector<int>(n + 1, 0));

        // Compute preSum using dynamic programming, starting from the bottom-right corner of the pizza
        for (int r = m - 1; r >= 0; r--)
            for (int c = n - 1; c >= 0; c--)
                prefSum[r][c] = prefSum[r][c + 1] + prefSum[r + 1][c] - prefSum[r + 1][c + 1] + (pizza[r][c] == 'A' ? 1 : 0);

        // Start the recursive function memoization with initial parameters
        // m = number of rows, n = number of columns, k = number of pieces we need to cut the pizza into,
        // r = row index where we start cutting, c = column index where we start cutting
        return memoization(m, n, k - 1, 0, 0, dp, prefSum);
    }

    // Recursive function to compute the number of ways to cut the remaining pizza into k pieces
    int memoization(int m, int n, int k, int r, int c, vector<vector<vector<int>>> &dp, vector<vector<int>> &prefSum)
    {
        // If the remaining piece has no apple, then it is an invalid cut and we return 0
        if (prefSum[r][c] == 0)
            return 0;

        // If we have found a valid way to cut the pizza into k pieces, then we return 1
        if (k == 0)
            return 1;

        // If the dp array already contains the number of ways to cut the remaining pizza into k pieces
        // starting from row r and column c, then we return the value from the dp array
        if (dp[k][r][c] != -1)
            return dp[k][r][c];

        int ans = 0;

        // Cut the pizza horizontally at position nr if the upper piece contains at least one apple
        for (int new_row = r + 1; new_row < m; new_row++)
        {
            if (prefSum[r][c] - prefSum[new_row][c] > 0)
                ans = (ans + memoization(m, n, k - 1, new_row, c, dp, prefSum)) % 1000000007;
        }

        // Cut the pizza vertically at position nc if the left piece contains at least one apple
        for (int new_col = c + 1; new_col < n; new_col++)
        {
            if (prefSum[r][c] - prefSum[r][new_col] > 0)
                ans = (ans + memoization(m, n, k - 1, r, new_col, dp, prefSum)) % 1000000007;
        }

        // Memoize the result in the dp array and return the result
        return dp[k][r][c] = ans;
    }
};

int main()
{
    vector<string> pizza = {"A..", "AAA", "..."};
    int k = 3;

    Solution obj;
    auto ans = obj.ways(pizza, k);
    cout << "The no. of ways to cut pizza are: " << ans << "\n";

    return 0;
}