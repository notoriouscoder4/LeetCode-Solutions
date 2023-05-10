/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Example 2:
Input: n = 1
Output: [[1]]

Constraints:
    1 <= n <= 20
*/

#include <bits/stdc++.h>
using namespace std;

/*
    TC: O(N^2)
    SC: O(N^2)
*/
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> spiralMatrix(n, vector<int>(n));

        int i = 0;   // row
        int j = 0;   // column
        int k = 1;   // it denotes the value which we want to fill in the spiral matrix
        int dir = 0; // 0 -> Right, 1 -> Down, 2 -> Left, 3 -> Up

        while (k <= n * n)
        {
            spiralMatrix[i][j] = k;
            k = k + 1;
            if (dir == 0)
            {
                j = j + 1;
                if (j == n || spiralMatrix[i][j] != 0)
                {
                    dir = 1;
                    j = j - 1;
                    i = i + 1;
                }
            }
            else if (dir == 1)
            {
                i = i + 1;
                if (i == n || spiralMatrix[i][j] != 0)
                {
                    dir = 2;
                    i = i - 1;
                    j = j - 1;
                }
            }
            else if (dir == 2)
            {
                j = j - 1;
                if (j < 0 || spiralMatrix[i][j] != 0)
                {
                    dir = 3;
                    j = j + 1;
                    i = i - 1;
                }
            }
            else if (dir == 3)
            {
                i = i - 1;
                if (i < 0 || spiralMatrix[i][j] != 0)
                {
                    dir = 0;
                    i = i + 1;
                    j = j + 1;
                }
            }
        }
        return spiralMatrix;
    }
};

/*
    TC: O(N^2)
    SC: O(N^2)
*/
class Solution_Recursive
{
public:
    void fillMatrix(vector<vector<int>> &spiralMatrix, int top, int bottom, int left, int right, int num)
    {
        if (top > bottom || left > right)
            return;

        for (int i = left; i <= right; i++)
        {
            spiralMatrix[top][i] = num;
            num++;
        }

        for (int i = top + 1; i <= bottom; i++)
        {
            spiralMatrix[i][right] = num;
            num++;
        }

        if (top < bottom && left < right)
        {
            for (int i = right - 1; i >= left; i--)
            {
                spiralMatrix[bottom][i] = num;
                num++;
            }
            for (int i = bottom - 1; i > top; i--)
            {
                spiralMatrix[i][left] = num;
                num++;
            }
        }
        fillMatrix(spiralMatrix, top + 1, bottom - 1, left + 1, right - 1, num);
    }

    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> spiralMatrix(n, vector<int>(n));
        fillMatrix(spiralMatrix, 0, n - 1, 0, n - 1, 1);
        return spiralMatrix;
    }
};

int main()
{
    int n = 3;
    Solution obj;
    auto ans = obj.generateMatrix(n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}