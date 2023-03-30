/*
Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land,
find a water cell such that its distance to the nearest land cell is maximized, and return the distance.
If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

Example 1:
Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.

Example 2:
Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.

Constraints:
    n == grid.length
    n == grid[i].length
    1 <= n <= 100
    grid[i][j] is 0 or 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Four directions: Up, Down, Left and Right.
    const pair<int, int> direction[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    /*
    Here N is the side of the square matrix with size N∗N.

    Time complexity: O(N^2)
    We start traversing from land cells (1) and keep iterating over water cells until we convert all water cells to land.
    Notice that we never insert any cell into the queue twice as we mark the water cell as land when we visit them.
    Therefore, the time complexity equals O(N^2)

    Space complexity: O(N^2)
    There could be all cells in the queue at a particular time. Considering the matrix doesn't have any water cells,
    we insert all the land cells into the queue to initialize and thus will take O(N^2) space.
    Also, we create visited, a copy matrix of grid.
    Hence, the space complexity is O(N^2)
    */
    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size();
        // A copy matrix of the grid to mark water cells as land once visited.
        int vis[n][n];

        // Insert all the land cells in the queue.
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // Copy grid to the visited matrix.
                vis[i][j] = grid[i][j];
                if (grid[i][j] == 1)
                    q.push({i, j});
            }
        }

        int distance = -1;
        while (!q.empty())
        {
            int qSize = q.size();

            // Iterate over all the current cells in the queue.
            while (qSize--)
            {
                pair<int, int> landCell = q.front();
                q.pop();

                // From the current land cell, traverse to all the four directions
                // and check if it is a water cell. If yes, convert it to land
                // and add it to the queue.
                for (pair<int, int> dir : direction)
                {
                    int x = landCell.first + dir.first;
                    int y = landCell.second + dir.second;

                    if (x >= 0 && y >= 0 && x < n && y < n && vis[x][y] == 0)
                    {
                        // Marking as 1 to avoid re-iterating it.
                        vis[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
            // After each iteration of queue elements, increment distance
            // as we covered 1 unit distance from all cells in every direction.
            distance++;
        }
        // If the distance is 0, there is no water cell.
        return distance == 0 ? -1 : distance;
    }

    /*
    Here NNN is the side of the square matrix with size N∗NN*NN∗N.

    Time complexity: O(N^2)
    We iterate over the matrix twice from top to bottom and bottom to top; hence the total time complexity equals O(N^2)

    Space complexity: O(N^2)

    The only space we need is the matrix dist of size N∗NN * NN∗N to store the minimum distance for all cells.
    Therefore, the total space complexity equals O(N^2)
    */
    int maxDistance_DP(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        // Maximum manhattan distance possible + 1.
        const int MAX_DISTANCE = rows + cols + 1;

        vector<vector<int>> dist(rows, vector<int>(cols, MAX_DISTANCE));

        // First pass: check for left and top neighbours
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                // Distance of land cells will be 0.
                if (grid[i][j])
                {
                    dist[i][j] = 0;
                }
                else
                {
                    // Check left and top cell distances if they exist and update the current cell distance.
                    dist[i][j] = min(dist[i][j], min(i > 0 ? dist[i - 1][j] + 1 : MAX_DISTANCE,
                                                     j > 0 ? dist[i][j - 1] + 1 : MAX_DISTANCE));
                }
            }
        }

        // Second pass: check for right and bottom neighbours.
        int ans = INT_MIN;
        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 0; j--)
            {
                // Check the right and bottom cell distances if they exist and update the current cell distance.
                dist[i][j] = min(dist[i][j], min(i < rows - 1 ? dist[i + 1][j] + 1 : MAX_DISTANCE,
                                                 j < cols - 1 ? dist[i][j + 1] + 1 : MAX_DISTANCE));
                ans = max(ans, dist[i][j]);
            }
        }

        // If ans is 0, it means there is no water cell,
        // If ans is MAX_DISTANCE, it implies no land cell.
        return ans == 0 || ans == MAX_DISTANCE ? -1 : ans;
    }

    int maxDistance_DP_Optimized(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        // Although it's a square matrix, using different variable for readability.
        int cols = grid[0].size();

        // Maximum manhattan distance possible + 1.
        const int MAX_DISTANCE = rows + cols + 1;

        // First pass: check for left and top neighbours
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j])
                {
                    // Distance of land cells will be 0.
                    grid[i][j] = 0;
                }
                else
                {
                    grid[i][j] = MAX_DISTANCE;
                    // Check left and top cell distances if they exist and update the current cell distance.
                    grid[i][j] = min(grid[i][j], min(i > 0 ? grid[i - 1][j] + 1 : MAX_DISTANCE,
                                                     j > 0 ? grid[i][j - 1] + 1 : MAX_DISTANCE));
                }
            }
        }

        // Second pass: check for right and bottom neighbours.
        int ans = INT_MIN;
        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 0; j--)
            {
                // Check the right and bottom cell distances if they exist and update the current cell distance.
                grid[i][j] = min(grid[i][j], min(i < rows - 1 ? grid[i + 1][j] + 1 : MAX_DISTANCE,
                                                 j < cols - 1 ? grid[i][j + 1] + 1 : MAX_DISTANCE));
                ans = max(ans, grid[i][j]);
            }
        }

        // If ans is 1, it means there is no water cell,
        // If ans is MAX_DISTANCE, it implies no land cell.
        return ans == 0 || ans == MAX_DISTANCE ? -1 : ans;
    }
};