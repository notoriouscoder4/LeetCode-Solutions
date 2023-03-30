/*
The Tribonacci sequence Tn is defined as follows:

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

Example 1:
Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4

Example 2:
Input: n = 25
Output: 1389537

Constraints:
    0 <= n <= 37
    The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[38];
    int f(int n)
    {
        if (n <= 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = f(n - 1) + f(n - 2) + f(n - 3);
    }
    int tribonacci_memoization(int n)
    {
        memset(dp, -1, sizeof(dp));
        return f(n);
    }
    int tribonacci_tabulation(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = dp[2] = 1;

        for (int i = 3; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }

    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        int a0 = 0, a1 = 1, a2 = 1, ans = 0;
        for (int i = 3; i <= n; i++)
        {
            ans = a0 + a1 + a2;
            a0 = a1;
            a1 = a2;
            a2 = ans;
        }
        return ans;
    }
};

int main()
{
    int n = 25;

    Solution obj;
    auto ans = obj.tribonacci_memoization(n);
    cout << ans << "\n";

    return 0;
}