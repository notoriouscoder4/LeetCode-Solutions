/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Example 2:
Input: grid = [[1,2,3],[4,5,6]]
Output: 12

Constraints:
    m == grid.length
    n == grid[i].length
    1 <= m, n <= 200
    0 <= grid[i][j] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> sum(n, vector<int>(m, grid[0][0]));
        for (int i = 1; i < n; i++)
            sum[i][0] = sum[i - 1][0] + grid[i][0];

        for (int j = 1; j < m; j++)
            sum[0][j] = sum[0][j - 1] + grid[0][j];

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                sum[i][j] = min(sum[i][j - 1], sum[i - 1][j]) + grid[i][j];
            }
        }

        return sum[n - 1][m - 1];
    }

    /*
        TC: O(n+m), SC: O(n)
    */
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // vector<vector<int>> sum(n, vector<int>(m, grid[0][0]));
        for (int i = 1; i < n; i++)
            grid[i][0] = grid[i - 1][0] + grid[i][0];

        for (int j = 1; j < m; j++)
            grid[0][j] = grid[0][j - 1] + grid[0][j];

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                grid[i][j] = min(grid[i][j - 1], grid[i - 1][j]) + grid[i][j];
            }
        }

        return grid[n - 1][m - 1];
    }
};