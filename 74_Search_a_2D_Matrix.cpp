/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix.
This matrix has the following properties:

1. Integers in each row are sorted from left to right.
2. The first integer of each row is greater than the last integer of the previous row.

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

Constraints:
    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 100
    -10^4 <= matrix[i][j], target <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();    // rows
        int n = matrix[0].size(); // cols

        int start = 0;
        int end = (m * n) - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            int i = mid / n; // it gives us ith index in matrix
            int j = mid % n; // it gives us jth index in matrix

            if (matrix[i][j] == target)
                return true;
            else if (target < matrix[i][j])
                end = mid - 1;
            else
                start = mid + 1;
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 13;

    Solution obj;
    auto ans = obj.searchMatrix(matrix, target);
    cout << ans << "\n";

    return 0;
}