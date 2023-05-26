/*
Alice and Bob continue their games with piles of stones.
There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].
The objective of the game is to end with the most stones.

Alice and Bob take turns, with Alice starting first.  Initially, M = 1.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.
Then, we set M = max(M, X).

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

Example 1:
Input: piles = [2,7,9,4,4]
Output: 10
Explanation:  If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total. If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 piles in total. So we return 10 since it's larger.

Example 2:
Input: piles = [1,2,3,4,5,100]
Output: 104

Constraints:
    1 <= piles.length <= 100
    1 <= piles[i] <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helper(vector<int> &piles, vector<vector<int>> &dp, const vector<int> &suffixSum, int i, int M)
    {
        if (i == piles.size())
            return 0;
        if (i + 2 * M >= piles.size())
            return suffixSum[i];
        if (dp[i][M] != 0)
            return dp[i][M];
        int result = 0;
        for (int x = 1; x <= 2 * M; ++x)
        {
            result = max(result, suffixSum[i] - helper(piles, dp, suffixSum, i + x, max(M, x)));
        }
        dp[i][M] = result;
        return result;
    }

    int stoneGameII(vector<int> &piles)
    {
        if (piles.empty())
            return 0;
        vector<vector<int>> dp(piles.size(), std::vector<int>(piles.size(), 0));
        vector<int> suffixSum(piles.size());
        suffixSum[suffixSum.size() - 1] = piles[piles.size() - 1];
        for (int i = piles.size() - 2; i >= 0; --i)
            suffixSum[i] = piles[i] + suffixSum[i + 1];
        return helper(piles, dp, suffixSum, 0, 1);
    }
};