/*
Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).


Example 1:

Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]

Explanation
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3

Constraints:
    1 <= nums.length <= 10^4
    -10^5 <= nums[i] <= 10^5
    0 <= left <= right < nums.length
    At most 10^4 calls will be made to sumRange.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Complexity

Time: Constructor: O(N), sumRange(left, right): O(1)
Space: O(1)
*/
class NumArray
{
public:
    vector<int> &preSum; // `preSum` will reference to `nums` array, no copy at all!
    NumArray(vector<int> &nums) : preSum(nums)
    {
        for (int i = 1; i < preSum.size(); i++)
            preSum[i] += preSum[i - 1];
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
            return preSum[right];
        return preSum[right] - preSum[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */