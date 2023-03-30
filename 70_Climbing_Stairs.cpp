/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Constraints:
    1 <= n <= 45
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int t[46];
    int climbStairs_memoization(int n)
    {
        if (n == 0 || n == 1)
            return 1;
        if (t[n] != -1)
            return t[n];
        return t[n] = climbStairs_memoization(n - 1) + climbStairs_memoization(n - 2);
    }
    int climbStairs_tabulation(int n)
    {
        int t[n + 1];
        t[0] = t[1] = 1;
        for (int i = 2; i <= n; i++)
            t[i] = t[i - 1] + t[i - 2];
        return t[n];
    }
    int climbStairs(int n)
    {
        memset(t, -1, sizeof(t));
        return climbStairs_memoization(n);
    }
};

int main()
{
    int n = 4;

    Solution obj;
    auto ans = obj.climbStairs(n);
    cout << ans << "\n";

    return 0;
}