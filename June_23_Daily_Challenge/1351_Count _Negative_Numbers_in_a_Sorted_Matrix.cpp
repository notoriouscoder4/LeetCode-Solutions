/*
Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

Example 1:
Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Example 2:
Input: grid = [[3,2],[1,0]]
Output: 0

Constraints:
    m == grid.length
    n == grid[i].length
    1 <= m, n <= 100
    -100 <= grid[i][j] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

/*
    TC: (MlogN)
    SC: O(1)
*/
class Solution_binary_search
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int cnt = 0;
        int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            int low = 0, high = m - 1;
            int ans = m;

            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (grid[i][mid] < 0)
                {
                    high = mid - 1;
                    ans = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }
            cnt += m - ans;
        }
        return cnt;
    }
};

/*
    TC: O(M+N)
    SC: O(1)
*/
class Solution_linear
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int cnt = 0;
        int n = grid[0].size();
        int currRowNegativeIndex = n - 1;

        for (auto &row : grid)
        {
            while (currRowNegativeIndex >= 0 && row[currRowNegativeIndex] < 0)
                currRowNegativeIndex--;
            cnt += (n - (currRowNegativeIndex + 1));
        }
        return cnt;
    }
};