/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

Constraints:
    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 10
    -100 <= matrix[i][j] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int left = 0;
        int top = 0;
        int right = matrix[0].size() - 1;
        int bottom = matrix.size() - 1;

        vector<int> result;

        while (top <= bottom && left <= right)
        {
            for (int j = left; j <= right; j++)
                result.push_back(matrix[top][j]);
            top++;

            for (int i = top; i <= bottom; i++)
                result.push_back(matrix[i][right]);
            right--;

            if (top <= bottom)
            {
                for (int j = right; j >= left; j--)
                    result.push_back(matrix[bottom][j]);
            }
            bottom--;

            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                    result.push_back(matrix[i][left]);
            }
            left++;
        }

        return result;
    }
};

class Solution_Iterative
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size(), dir = 0;                         // direction
        vector<int> result(m * n), curr = {0, 0};                                     // {r, c}
        vector<vector<int>> limit = {{0, n - 1}, {m - 1, n - 1}, {m - 1, 0}, {1, 0}}, // boundaries
            dCurr = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}},                               // {dr, dc}
            dLimit = {{1, -1}, {-1, -1}, {-1, 1}, {1, 1}};                            // change in boundaries
        for (int i = 0; i < m * n; i++)
        {
            result[i] = matrix[curr[0]][curr[1]];
            if (curr == limit[dir])
            {                                                                                  // change direction
                limit[dir] = {limit[dir][0] + dLimit[dir][0], limit[dir][1] + dLimit[dir][1]}; // change boundary
                dir = (dir + 1) % 4;
            }
            curr = {curr[0] + dCurr[dir][0], curr[1] + dCurr[dir][1]};
        }
        return result;
    }
};

class Solution_Recursion
{
private:
    vector<int> result;

    void oneSpiral(vector<vector<int>> &matrix, int r1, int r2, int c1, int c2)
    {
        if (r1 > r2 || c1 > c2)
        {
            return;
        }
        int dir = 0;
        vector<int> curr = {r1, c1};                                              // curr = {r, c}
        vector<vector<int>> limit = {{r1, c2}, {r2, c2}, {r2, c1}, {r1 + 1, c1}}, // boundaries
            dcurr = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {0, 0}};                   // dcurr = {dr, dc} for directions {right, down, left, up, invalid}
        auto isValid = [&](int r, int c)
        { return r1 <= r && r <= r2 && c1 <= c && c <= c2; };
        while (dir < 4 && isValid(curr[0], curr[1]))
        {
            result.push_back(matrix[curr[0]][curr[1]]);
            if (curr == limit[dir])
            { // change direction
                dir++;
            }
            curr = {curr[0] + dcurr[dir][0], curr[1] + dcurr[dir][1]}; // next cell
        }
        oneSpiral(matrix, r1 + 1, r2 - 1, c1 + 1, c2 - 1);
    }

public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        oneSpiral(matrix, 0, m - 1, 0, n - 1);
        result.resize(m * n); // to avoid duplicates
        return result;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    Solution obj;
    auto ans = obj.spiralOrder(matrix);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}