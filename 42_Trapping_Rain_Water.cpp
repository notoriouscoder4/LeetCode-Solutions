/*
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it can trap after raining.

Example 1:
    Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
    Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
    In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
    Input: height = [4,2,0,3,2,5]
    Output: 9

Constraints:
    n == height.length
    1 <= n <= 2 * 10^4
    0 <= height[i] <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Given elevation map array, compute trapped water
    Ex. height = [0,1,0,2,1,0,1,3,2,1,2,1] -> 6

    2 pointers, outside in, track max left/right
    For lower max, curr only dependent on that one
    Compute height of these, iterate lower one

    Time: O(n)
    Space: O(1)
*/
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int i = 0;
        int j = height.size() - 1;

        int maxLeft = height[i];
        int maxRight = height[j];

        int result = 0;
        while (i < j)
        {
            if (maxLeft <= maxRight)
            {
                i++;
                maxLeft = max(maxLeft, height[i]);
                result += maxLeft - height[i];
            }
            else
            {
                j--;
                maxRight = max(maxRight, height[j]);
                result += maxRight - height[j];
            }
        }

        return result;
    }
};

int main()
{
    vector<int> height = {4, 2, 0, 3, 2, 5};
    Solution obj;

    auto ans = obj.trap(height);
    cout << "water can be trapped after raining: " << ans << "\n";

    return 0;
}