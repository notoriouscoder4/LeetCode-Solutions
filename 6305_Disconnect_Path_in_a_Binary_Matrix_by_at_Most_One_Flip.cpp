/*
You are given a 0-indexed m x n binary matrix grid. You can move from a cell (row, col) to any of the cells (row + 1, col) or (row, col + 1) that has the value 1.
The matrix is disconnected if there is no path from (0, 0) to (m - 1, n - 1).

You can flip the value of at most one (possibly none) cell. You cannot flip the cells (0, 0) and (m - 1, n - 1).

Return true if it is possible to make the matrix disconnect or false otherwise.

Note that flipping a cell changes its value from 0 to 1 or from 1 to 0.

Example 1:
Input: grid = [[1,1,1],[1,0,0],[1,1,1]]
Output: true
Explanation: We can change the cell shown in the diagram above. There is no path from (0, 0) to (2, 2) in the resulting grid.

Example 2:
Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
Output: false
Explanation: It is not possible to change at most one cell such that there is not path from (0, 0) to (2, 2).

Constraints:
    m == grid.length
    n == grid[i].length
    1 <= m, n <= 1000
    1 <= m * n <= 10^5
    grid[i][j] is either 0 or 1.
    grid[0][0] == grid[m - 1][n - 1] == 1
*/

#include <bits/stdc++.h>
using namespace std;

int direction[][2] = {{0, 1}, {1, 0}};
bool dfs(vector<vector<int>> &grid, int i, int j, int n, int m)
{
    if (i == n - 1 and j == m - 1)
        return true;
    grid[i][j] = 0;
    for (int k = 0; k < 2; k++)
    {
        int new_x = i + direction[k][0];
        int new_y = j + direction[k][1];
    }
}

class Solution
{
public:
    bool isPossibleToCutPath_DP(vector<vector<int>> &grid)
    {
        long double m = grid.size();
        long double n = grid[0].size();
        vector<vector<long double>> dp(m, vector<long double>(n, 0));
        dp[0][0] = 1;
        for (long long int i = 0; i < m; i++)
        {
            for (long long int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                if (grid[i][j] == 0)
                    continue;
                long double ans = 0;
                if (i - 1 >= 0)
                    ans += dp[i - 1][j];
                if (j - 1 >= 0)
                    ans += dp[i][j - 1];
                dp[i][j] = ans;
            }
        }
        vector<vector<long double>> dp2(m, vector<long double>(n, 0));
        dp2[m - 1][n - 1] = 1;
        for (long long i = m - 1; i >= 0; i--)
        {
            for (long long int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 && j == n - 1)
                    continue;
                if (grid[i][j] == 0)
                    continue;
                long double ans = 0;
                if (i + 1 < m)
                    ans += dp2[i + 1][j];
                if (j + 1 < n)
                    ans += dp2[i][j + 1];
                dp2[i][j] = ans;
            }
        }
        if (dp[m - 1][n - 1] == 0)
            return true;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                if (i == m - 1 && j == n - 1)
                    continue;
                if (grid[i][j] == 0)
                    continue;
                if (i + 1 < m && dp[i][j] != dp[i + 1][j])
                    continue;
                if (j + 1 < n && dp[i][j] != dp[i][j + 1])
                    continue;
                long double temp = 0;
                if (i + 1 < m)
                    temp += dp2[i + 1][j];
                if (j + 1 < n)
                    temp += dp2[i][j + 1];
                if (dp[m - 1][n - 1] == dp[i][j] * (temp))
                    return true;
            }
        }
        return false;
    }

    bool isPossibleToCutPath(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<int> v(m + n - 1, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    v[i + j]++;
            }
        }

        for (int i = 1; i < v.size() - 1; i++)
        {
            if (v[i] <= 1)
                return true;
        }
        return false;
    }
};