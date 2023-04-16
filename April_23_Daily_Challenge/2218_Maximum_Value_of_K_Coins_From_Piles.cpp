/*
There are n piles of coins on a table. Each pile consists of a positive number of coins of assorted denominations.

In one move, you can choose any coin on top of any pile, remove it, and add it to your wallet.

Given a list piles, where piles[i] is a list of integers denoting the composition of the ith pile from top to bottom,
and a positive integer k, return the maximum total value of coins you can have in your wallet if you choose exactly k coins optimally.


Example 1:
Input: piles = [[1,100,3],[7,8,9]], k = 2
Output: 101
Explanation:
The above diagram shows the different ways we can choose k coins.
The maximum total we can obtain is 101.

Example 2:
Input: piles = [[100],[100],[100],[100],[100],[100],[1,1,1,1,1,1,700]], k = 7
Output: 706
Explanation:
The maximum total can be obtained if we choose all coins from the last pile.

Constraints:
    n == piles.length
    1 <= n <= 1000
    1 <= piles[i][j] <= 10^5
    1 <= k <= sum(piles[i].length) <= 2000
*/

#include <bits/stdc++.h>
using namespace std;

/*
Intuition
    The problem can be approached using dynamic programming by breaking it down into subproblems.
    We can create a 2D array dp[i][j] to store the maximum value of coins for choosing j coins from the first i piles.
    Then, we can iterate through the array and compute the maximum value of coins for each subproblem by trying all possible choices for the current pile and updating the maximum result.

Approach
    1. Create a 2D array dp[i][j] to store the maximum value of coins for choosing j coins from the first i piles.

    2. Fill the first row and column of the array with zeros.

    3. Iterate through the array and compute the maximum value of coins for each subproblem by trying all possible choices for the current pile and updating the maximum result.

    4. If not choosing any coin from the current pile gives a better result, use that instead.

    5. The last element of the array is the maximum value of coins for choosing k coins from all the piles.

Complexity
    Time complexity:
    O(n*k), where n is the maximum number of coins in a pile.
    The outer loop runs n times, the inner loop runs k times, and the innermost loop runs n times in the worst case.

    Space complexity:
    O(n*k), since we are using a 2D array of size (n+1) x (k+1) to store the results.
*/
class Solution
{
public:
    int func(int i, int k, vector<vector<int>> &piles, vector<vector<int>> &dp)
    {
        // recursion stopping condition, as positive number of coins
        if (dp[i][k] > 0)
            return dp[i][k];
        // When piles are done OR when coins to pick up are done
        if (i == piles.size() || k == 0)
            return 0;

        // Take no coin from pile
        int res = func(i + 1, k, piles, dp), cur = 0;

        // j < k means count of coins we are taking such that we do not cross k, j+1 <= k
        for (int j = 0; j < piles[i].size() && j < k; ++j)
        {
            cur += piles[i][j];
            // k-j-1 == k-(j+1), it means how many picks we are left of
            res = max(res, func(i + 1, k - j - 1, piles, dp) + cur);
        }
        dp[i][k] = res;
        return res;
    }

    int maxValueOfCoins(vector<vector<int>> &piles, int k)
    {
        int n = piles.size();
        vector<vector<int>> t(n + 1, vector<int>(k + 1, 0));
        return func(0, k, piles, t);
    }
};

int main()
{
    vector<vector<int>> piles = {{1, 100, 3}, {7, 8, 9}};
    int k = 2;

    Solution obj;
    auto ans = obj.maxValueOfCoins(piles, k);
    cout << ans << "\n";

    return 0;
}