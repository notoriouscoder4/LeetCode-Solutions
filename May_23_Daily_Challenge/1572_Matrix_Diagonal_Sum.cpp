/*
Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

Example 1:
Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.

Example 2:
Input: mat = [[1,1,1,1],
              [1,1,1,1],
              [1,1,1,1],
              [1,1,1,1]]
Output: 8

Example 3:
Input: mat = [[5]]
Output: 5

Constraints:
    n == mat.length == mat[i].length
    1 <= n <= 100
    1 <= mat[i][j] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

/*
Intuition
    We can see that elements along the primary diagonals have the same row and column number.
    So, all elements of the form mat[i][i] with i ranging from i = 0 to i = n - 1, where n is the number of rows (or columns) in mat, form the primary diagonal.

    Let's form the secondary diagnal starting with the last row and first column, i.e., mat[n - 1][0].
    mat[n - 2][1] is the next element over the secondary diagonal, one row up and one column ahead.
    The following element, mat[n - 3][2], is again one row up and one column ahead of the previous element.
    The final element is mat[0][n - 1]. We can notice that the sum of the row and column numbers is constant (n - 1) because the column increases by one but the row decreases by one.
    As a result, all elements of the form mat[n - 1 - i][i] with i ranging from i = 0 to i = n - 1 constitute the secondary diagonal.

    When we compare a square matrix with an odd number of rows to a square matrix with an even number of rows,
    we notice that there is a common element mat[n / 2][n / 2] at the intersection of the primary and secondary diagonals in the case of the matrix with odd rows:

    We add the elements on the primary and secondary diagonals and deduct the common element if number of rows in mat is odd.

Algorithm
    1. Create an integer n that stores the number of rows (or columns) in mat.
    2. Create an answer variable ans which will store the sum of elements on the primary and secondary diagonals. Initialize it to 0.
    3. Iterate from i = 0 to i = n - 1:
        3a. Add elements on the primary diagonal to ans. We perform ans += mat[i][i].
        3b. Add elements on the secondary diagonal to ans. We perform ans += mat[n - 1 - i][i].
    4. If the number of rows in mat is odd, we have a common element between the primary and secondary diagonals.
    We decrement it from ans. We perform ans -= mat[n / 2][n / 2].
    5. Return ans.
*/

/*
    TC: O(N)
    SC: O(1)
*/
class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += mat[i][i];
            sum += mat[n - i - 1][i];
        }
        if (n % 2 != 0)
            sum -= mat[n / 2][n / 2];
        return sum;
    }
};