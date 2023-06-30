/*

*/

#include <bits/stdc++.h>
using namespace std;

/*
Binary Search + Depth-First Search
    Time complexity: O(row⋅col⋅log⁡row⋅col)

    . The binary search over a search space of size n takes O(log⁡n) steps to find the last day that we can still cross. The size of our search space is row⋅col.
    . The DFS method visits each cell at most once, which takes O(row⋅col) time.

    Space complexity: O(row⋅col)

    . We need to build an 2-D array of size row×col.
    . The recursion call stack from the DFS could use up to O(row⋅col) space.
*/
class Solution_Binary_Search_DFS
{
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool canCross(int row, int col, vector<vector<int>> &cells, int day)
    {
        vector<vector<int>> grid(row, vector<int>(col, 0));

        for (int i = 0; i < day; ++i)
        {
            int r = cells[i][0] - 1, c = cells[i][1] - 1;
            grid[r][c] = 1;
        }

        for (int i = 0; i < day; ++i)
        {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        for (int i = 0; i < col; ++i)
        {
            if (grid[0][i] == 0 && dfs(grid, 0, i, row, col))
            {
                return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<int>> &grid, int r, int c, int row, int col)
    {
        if (r < 0 || r >= row || c < 0 || c >= col || grid[r][c] != 0)
        {
            return false;
        }

        if (r == row - 1)
        {
            return true;
        }

        grid[r][c] = -1;

        for (auto &dir : directions)
        {
            int newR = r + dir[0], newC = c + dir[1];
            if (dfs(grid, newR, newC, row, col))
            {
                return true;
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        int left = 1, right = row * col;
        while (left < right)
        {
            int mid = right - (right - left) / 2;
            if (canCross(row, col, cells, mid))
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};

/*
Binary Search + Breadth-First Search
    Time complexity: O(row⋅col⋅log⁡row⋅col)

    . The binary search over a search space of size n takes O(log⁡n) steps to find the last day that we can still cross. The size of our search space is row⋅col.
    . At each step, we need to BFS over the modified grid, which takes O(row⋅col) time.

    Space complexity: O(row⋅col)

    . We need to build an 2-D array of size row×col.
    . During the BFS, we might have at most O(row⋅col) in queue.
*/
class Solution_Binary_Search_BFS
{
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool canCross(int row, int col, vector<vector<int>> &cells, int day)
    {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        queue<vector<int>> queue;

        for (int i = 0; i < day; i++)
        {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        for (int i = 0; i < col; i++)
        {
            if (grid[0][i] == 0)
            {
                queue.push({0, i});
                grid[0][i] = -1;
            }
        }

        while (!queue.empty())
        {
            vector<int> cur = queue.front();
            queue.pop();
            int r = cur[0], c = cur[1];

            if (r == row - 1)
            {
                return true;
            }

            for (auto &dir : directions)
            {
                int newRow = r + dir[0];
                int newCol = c + dir[1];
                if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && grid[newRow][newCol] == 0)
                {
                    grid[newRow][newCol] = -1;
                    queue.push({newRow, newCol});
                }
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        int left = 1, right = row * col;
        while (left < right)
        {
            int mid = right - (right - left) / 2;
            if (canCross(row, col, cells, mid))
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};