/*
There is a function signFunc(x) that returns:

    1. 1 if x is positive.
    2. -1 if x is negative.
    3. 0 if x is equal to 0.

You are given an integer array nums. Let product be the product of all values in the array nums.

Return signFunc(product).


Example 1:
Input: nums = [-1,-2,-3,-4,3,2,1]
Output: 1
Explanation: The product of all values in the array is 144, and signFunc(144) = 1

Example 2:
Input: nums = [1,5,0,2,-3]
Output: 0
Explanation: The product of all values in the array is 0, and signFunc(0) = 0

Example 3:
Input: nums = [-1,1,-1,1,-1]
Output: -1
Explanation: The product of all values in the array is -1, and signFunc(-1) = -1

Constraints:
    1 <= nums.length <= 1000
    -100 <= nums[i] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

class Solution_Counting_Negative_Numbers
{
public:
    int arraySign(vector<int> &nums)
    {
        int countNegativeNumbers = 0;
        for (int num : nums)
        {
            if (num == 0)
                return 0;
            if (num < 0)
                countNegativeNumbers++;
        }
        return countNegativeNumbers % 2 == 0 ? 1 : -1;
    }
};

class Solution_Tracking_the_Sign_of_the_Product
{
public:
    int arraySign(vector<int> &nums)
    {
        int sign = 1;
        for (int num : nums)
        {
            if (num == 0)
                return 0;
            if (num < 0)
                sign = -1 * sign;
        }
        return sign;
    }
};

int main()
{
    vector<int> nums = {-1, -2, -3, -4, 3, 2, 1};

    Solution_Counting_Negative_Numbers obj;
    auto ans = obj.arraySign(nums);
    cout << ans << "\n";

    return 0;
}