/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

Example 1:
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

Example 2:
Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.

Example 3:
Input: amount = 10, coins = [10]
Output: 1

Constraints:
    1 <= coins.length <= 300
    1 <= coins[i] <= 5000
    All the values of coins are unique.
    0 <= amount <= 5000
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int recursion(int amount, vector<int> coins, int n)
    {
        if (n == 0 || amount == 0)
            return amount == 0 ? 1 : 0;

        if (coins[n - 1] <= amount)
            return recursion(amount, coins, n - 1) + recursion(amount - coins[n - 1], coins, n);
        else
            return recursion(amount, coins, n - 1);
    }

    int change(int amount, vector<int> &coins)
    {
        return recursion(amount, coins, coins.size());
    }
};

class Solution
{
public:
    int t[5000 + 1][300 + 1];
    int memoization(int amount, vector<int> coins, int n)
    {
        if (n == 0 || amount == 0)
            return amount == 0 ? 1 : 0;

        if (t[amount][n] != -1)
            return t[amount][n];

        if (coins[n - 1] <= amount)
            return t[amount][n] = memoization(amount, coins, n - 1) + memoization(amount - coins[n - 1], coins, n);
        else
            return t[amount][n] = memoization(amount, coins, n - 1);
    }

    int change(int amount, vector<int> &coins)
    {
        memset(t, -1, sizeof(t));
        return memoization(amount, coins, coins.size());
    }
};

class Solution
{
public:
    int dp[5000 + 1][300 + 1];

    int tabulation(int amount, vector<int> &coins, int n)
    {
        for (int i = 0; i < amount + 1; i++)
            for (int j = 0; j < n + 1; j++)
                if (i == 0 || j == 0)
                    dp[i][j] = ((i == 0) ? 1 : 0);

        for (int i = 1; i < amount + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (coins[j - 1] > i)
                    dp[i][j] = dp[i][j - 1];
                else
                    dp[i][j] = dp[i][j - 1] + dp[i - coins[j - 1]][j];
            }
        }

        return dp[amount][n];
    }

    int change(int amount, vector<int> &coins)
    {
        memset(dp, -1, sizeof(dp));
        return tabulation(amount, coins, coins.size());
    }
};