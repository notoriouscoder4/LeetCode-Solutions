/*
There is a 1-based binary matrix where 0 represents land and 1 represents water.
You are given integers row and col representing the number of rows and columns in the matrix, respectively.

Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water.
You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day,
the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).

You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells.
You can start from any cell in the top row and end at any cell in the bottom row.
You can only travel in the four cardinal directions (left, right, up, and down).

Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.

Example 1:
Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
Output: 2
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 2.

Example 2:
Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
Output: 1
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 1.

Example 3:
Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
Output: 3
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 3.

Constraints:
    2 <= row, col <= 2 * 10^4
    4 <= row * col <= 2 * 10^4
    cells.length == row * col
    1 <= ri <= row
    1 <= ci <= col
    All the values of cells are unique.
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