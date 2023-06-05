/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point.
Check if these points make a straight line in the XY plane.

Example 1:
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

Example 2:
Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false

Constraints:
    2 <= coordinates.length <= 1000
    coordinates[i].length == 2
    -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
    coordinates contains no duplicate point.
*/

#include <bits/stdc++.h>
using namespace std;

/*
We are given N points (x, y), where x and y represent the coordinates. We must return true if the points make a straight line and false otherwise.

To solve this problem, we will use the slope property of a straight line. The slope of a line is defined as the change in Y coordinates with respect to the change in X coordinates of any two points on the line.

Slope = ΔY/ΔX

The property that can be used to solve this problem is that the slope between any two points on a straight line will be the same. If we choose two points from the given list of points, the value of Slope as defined above should be the same.
*/
class Solution
{
public:
    // Returns the delta Y.
    int getYDiff(vector<int> &a, vector<int> &b)
    {
        return a[1] - b[1];
    }

    // Returns the delta X.
    int getXDiff(vector<int> &a, vector<int> &b)
    {
        return a[0] - b[0];
    }

    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        int deltaY = getYDiff(coordinates[1], coordinates[0]);
        int deltaX = getXDiff(coordinates[1], coordinates[0]);

        for (int i = 2; i < coordinates.size(); i++)
        {
            // Check if the slope between points 0 and i, is the same as between 0 and 1.
            if (deltaY * getXDiff(coordinates[i], coordinates[0]) != deltaX * getYDiff(coordinates[i], coordinates[0]))
                return false;
        }
        return true;
    }
};