/*
You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.

In the ith operation (1-indexed), you will:

1. Choose two elements, x and y.
2. Receive a score of i * gcd(x, y).
3. Remove x and y from nums.

Return the maximum score you can receive after performing n operations.

The function gcd(x, y) is the greatest common divisor of x and y.

Example 1:
Input: nums = [1,2]
Output: 1
Explanation: The optimal choice of operations is:
(1 * gcd(1, 2)) = 1

Example 2:
Input: nums = [3,4,6,8]
Output: 11
Explanation: The optimal choice of operations is:
(1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11

Example 3:
Input: nums = [1,2,3,4,5,6]
Output: 14
Explanation: The optimal choice of operations is:
(1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14

Constraints:
    1 <= n <= 7
    nums.length == 2 * n
    1 <= nums[i] <= 10^6
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int memoization(vector<int> &nums, int op, int mask, vector<int> &t)
    {
        int m = nums.size(), n = nums.size() / 2;

        if (op > n)
            return 0;
        if (t[mask] != -1)
            return t[mask];

        for (int i = 0; i < m; i++)
        {
            if ((mask & (1 << i)) == 1)
                continue;
            for (int j = i + 1; j < m; j++)
            {
                if ((mask & (1 << j)))
                    continue;
                int newMask = (1 << i) | (1 << j) | mask;
                int score = op * __gcd(nums[i], nums[j]) + memoization(nums, op + 1, newMask, t);
                t[mask] = max(t[mask], score);
            }
        }
        return t[mask];
    }

    int maxScore(vector<int> &nums)
    {
        vector<int> t(1 << 14, -1);
        return memoization(nums, 1, 0, t);
    }
};

// precalculated gcd
class Solution_optimized
{
public:
    int memoization(vector<int> &nums, int op, int mask, vector<int> &dp, vector<vector<int>> &gcd)
    {
        int m = nums.size(), n = nums.size() / 2;
        if (op > n)
            return 0;
        if (dp[mask] != -1)
            return dp[mask];

        for (int i = 0; i < m; i++)
        {
            if ((mask & (1 << i)))
                continue;
            for (int j = i + 1; j < m; j++)
            {
                if ((mask & (1 << j)))
                    continue;

                int newMask = (1 << i) | (1 << j) | mask;
                int score = op * gcd[i][j] + memoization(nums, op + 1, newMask, dp, gcd);
                dp[mask] = max(dp[mask], score);
            }
        }
        return dp[mask];
    }

    int maxScore(vector<int> &nums)
    {
        vector<int> dp(1 << 14, -1);

        int m = nums.size(), n = nums.size() / 2;
        vector<vector<int>> gcd(m, vector<int>(m, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                gcd[i][j] = __gcd(nums[i], nums[j]);
            }
        }

        return memoization(nums, 1, 0, dp, gcd);
    }
};