/*
Given an integer array nums, handle multiple queries of the following types:

Update the value of an element in nums.
Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.

Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
void update(int index, int val) Updates the value of nums[index] to be val.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).


Example 1:

Input
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output
[null, 9, null, 8]

Explanation
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8

Constraints:
    1 <= nums.length <= 3 * 10^4
    -100 <= nums[i] <= 100
    0 <= index < nums.length
    -100 <= val <= 100
    0 <= left <= right < nums.length
    At most 3 * 10^4 calls will be made to update and sumRange.
*/

#include <bits/stdc++.h>
using namespace std;

class BIT // Binary Indexed Tree: One-based indexing
{
    vector<int> bit;

public:
    BIT(int size = 0)
    {
        bit.assign(size + 1, 0);
    }
    int getSum(int idx) // Get sum in range [1..idx]
    {
        int sum = 0;
        for (; idx > 0; idx -= (idx & -idx))
            sum += bit[idx];
        return sum;
    }
    void addValue(int idx, int val)
    {
        for (; idx < bit.size(); idx += (idx & -idx))
            bit[idx] += val;
    }
};

class NumArray
{
    BIT bit;
    vector<int> nums;

public:
    NumArray(vector<int> &nums)
    {
        this->bit = BIT(nums.size());
        this->nums = nums;

        for (int i = 0; i < nums.size(); i++)
            bit.addValue(i + 1, nums[i]);
    }

    void update(int index, int val)
    {
        int diff = val - nums[index];  // get diff amount of `val` compared to current value
        bit.addValue(index + 1, diff); // add this `diff` amount at index `index+1` of BIT, plus 1 because in BIT it's 1-based indexing

        nums[index] = val; // update latest value of `nums[index]`
    }

    int sumRange(int left, int right)
    {
        return bit.getSum(right + 1) - bit.getSum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */