/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.


Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Example 3:
Input: coins = [1], amount = 0
Output: 0

Constraints:
    1 <= coins.length <= 12
    1 <= coins[i] <= 2^31 - 1
    0 <= amount <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findFewestCoins_recursion(vector<int> &coins, int ind, int amount)
    {
        if (ind >= coins.size() || amount <= 0)
            return (amount == 0) ? 0 : INT_MAX - 1;

        int res = -1;
        if (coins[ind] <= amount)
        {
            int takeCoin = 1 + findFewestCoins_recursion(coins, ind + 0, amount - coins[ind]);
            int doNotTakeCoin = 0 + findFewestCoins_recursion(coins, ind + 1, amount - 0);
            res = min(takeCoin, doNotTakeCoin);
        }
        else
        {
            int doNotTakeCoin = 0 + findFewestCoins_recursion(coins, ind + 1, amount - 0);
            res = doNotTakeCoin;
        }
        return res;
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int res = findFewestCoins_recursion(coins, 0, amount);
        return (res == INT_MAX - 1) ? -1 : res;
    }
};

class Solution
{
public:
    int t[12 + 1][10000 + 1];
    int findFewestCoins_memoization(vector<int> &coins, int ind, int amount)
    {
        if (ind >= coins.size() || amount <= 0)
            return (amount == 0) ? 0 : INT_MAX - 1;

        if (t[ind][amount] != -1)
            return t[ind][amount];

        int res = -1;
        if (coins[ind] <= amount)
        {
            int takeCoin = 1 + findFewestCoins_memoization(coins, ind + 0, amount - coins[ind]);
            int doNotTakeCoin = 0 + findFewestCoins_memoization(coins, ind + 1, amount - 0);
            t[ind][amount] = res = min(takeCoin, doNotTakeCoin);
        }
        else
        {
            int doNotTakeCoin = 0 + findFewestCoins_memoization(coins, ind + 1, amount - 0);
            t[ind][amount] = res = doNotTakeCoin;
        }
        return t[ind][amount] = res;
    }

    int coinChange(vector<int> &coins, int amount)
    {
        memset(t, -1, sizeof(t));
        int res = findFewestCoins_memoization(coins, 0, amount);
        return (res == INT_MAX - 1) ? -1 : res;
    }
};

class Solution
{
public:
    int dp[12 + 1][10000 + 1];

    int findLowestCoins_tabulation(vector<int> &coins, int arraySize, int amount)
    {
        for (int i = 0; i < arraySize + 1; i++)
            for (int j = 0; j < amount + 1; j++)
                if (i == 0 || j == 0)
                    dp[i][j] = (j == 0) ? 0 : INT_MAX - 1;

        for (int i = 1; i < arraySize + 1; i++)
        {
            for (int j = 1; j < amount + 1; j++)
            {
                if (coins[i - 1] > j)
                    dp[i][j] = 0 + dp[i - 1][j];
                else
                    dp[i][j] = min(0 + dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            }
        }

        return dp[arraySize][amount];
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int res = findLowestCoins_tabulation(coins, coins.size(), amount);
        return (res == INT_MAX - 1) ? -1 : res;
    }
};