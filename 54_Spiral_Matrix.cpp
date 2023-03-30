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

/*
    Given a matrix, return all elements in spiral order

    Set up boundaries, go outside in CW: top->right->bottom->left

    Time: O(m x n)
    Space: O(m x n)
*/
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
            for (int j = left; j <= right; ++j)
                result.push_back(matrix[top][j]);
            top++;

            for (int i = top; i <= bottom; ++i)
                result.push_back(matrix[i][right]);

            right--;

            if (top <= bottom)
            {
                for (int j = right; j >= left; --j)
                    result.push_back(matrix[bottom][j]);
            }
            bottom--;

            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    result.push_back(matrix[i][left]);
                }
            }
            left++;
        }
        return result;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    Solution obj;
    auto ans = obj.spiralOrder(matrix);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i];

    return 0;
}