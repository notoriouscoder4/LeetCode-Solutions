/*
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix.
If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

    . All the visited cells of the path are 0.
    . All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).

The length of a clear path is the number of visited cells of this path.

Example 1:
Input: grid = [[0,1],[1,0]]
Output: 2

Example 2:
Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

Example 3:
Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1

Constraints:
    n == grid.length
    n == grid[i].length
    1 <= n <= 100
    grid[i][j] is 0 or 1
*/

#include <bits/stdc++.h>
using namespace std;

/*  BFS Algo
    TC: O(N*M)
    SC: O(N*M)
*/
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        // create queue of pair of initial position {0,0} with length = 1
        queue<pair<pair<int, int>, int>> q;
        // push initial psotion i.e. {0,0} with length i.e. 1
        q.push({{0, 0}, 1});

        // we can't move if initial position i.e. {0,0} has 1 because it is not valid cell according to problem statement
        if (grid[0][0] == 1)
            return -1;
        // if there is only one cell present and the value at that cell = 0 then length will always be 1 only
        // because we are already at the destination
        if (grid[0][0] == 0 && grid.size() == 1 && grid[0].size() == 1)
            return 1;

        // create an array of array of boolean value because we want to keep track of positions
        // with initial position as {0,0}
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size(), false));
        visited[0][0] = true;

        // traverse through the matrix
        while (!q.empty())
        {

            // pick the initial position from queue i.e. the first part of pair
            pair<int, int> p = q.front().first;
            int x = p.first;
            int y = p.second;
            // length is second part of the pair in the queue
            int lengthOfPath = q.front().second;
            q.pop();

            // create an array of pair of int of size 8 because the matrix is 8-directionally connected
            vector<pair<int, int>> neighbors = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

            // pick every direction from neighbors array and try to move in all remaining direction
            for (pair<int, int> neighbor : neighbors)
            {
                int newX = neighbor.first + x;
                int newY = neighbor.second + y;

                // this check is for if we are in bound of the matrix and if we are then we can move
                if (newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid[0].size() && grid[newX][newY] == 0 && !visited[newX][newY])
                {
                    // for making the movement we have push the new direction/position in the queue with its length plus 1
                    // because we have moved one valid position ahead
                    q.push({{newX, newY}, lengthOfPath + 1});
                    visited[newX][newY] = true;

                    // if we have reached at the last position in the matrix that means we have moved correctly
                    // return length of path plus 1 because of valid position
                    if (newX == grid.size() - 1 && newY == grid[0].size() - 1)
                        return lengthOfPath + 1;
                }
            }
        }
        return -1;
    }
};