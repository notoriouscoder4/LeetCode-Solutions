/*
You are given an m x n integer matrix grid, where you can move from a cell to any adjacent cell in all 4 directions.

Return the number of strictly increasing paths in the grid such that you can start from any cell and end at any cell.
Since the answer may be very large, return it modulo 10^9 + 7.

Two paths are considered different if they do not have exactly the same sequence of visited cells.

Example 1:
Input: grid = [[1,1],[3,4]]
Output: 8
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [1], [3], [4].
- Paths with length 2: [1 -> 3], [1 -> 4], [3 -> 4].
- Paths with length 3: [1 -> 3 -> 4].
The total number of paths is 4 + 3 + 1 = 8.

Example 2:
Input: grid = [[1],[2]]
Output: 3
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [2].
- Paths with length 2: [1 -> 2].
The total number of paths is 2 + 1 = 3.

Constraints:
    m == grid.length
    n == grid[i].length
    1 <= m, n <= 1000
    1 <= m * n <= 10^5
    1 <= grid[i][j] <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1000000007;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool isvalid(int x, int y, vector<vector<int>> &grid)
    {
        if (x < 0 or x >= grid.size() or y < 0 or y >= grid[0].size())
            return false;
        return true;
    }
    int dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (dp[x][y] != -1)
            return dp[x][y];
        int ans = 1;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (isvalid(nx, ny, grid) and grid[x][y] < grid[nx][ny])
            {
                ans = (ans % mod + dfs(nx, ny, grid, dp) % mod) % mod;
            }
        }
        return dp[x][y] = ans % mod;
    }
    int countPaths(vector<vector<int>> &grid)
    {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        long long count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                count = (count % mod + dfs(i, j, grid, dp) % mod) % mod;
            }
        }
        return (int)count % mod;
    }
};