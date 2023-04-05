/*
You are given a 0-indexed array nums comprising of n non-negative integers.

In one operation, you must:
    1. Choose an integer i such that 1 <= i < n and nums[i] > 0.
    2. Decrease nums[i] by 1.
    3. Increase nums[i - 1] by 1.
Return the minimum possible value of the maximum integer of nums after performing any number of operations.

Example 1:
Input: nums = [3,7,1,6]
Output: 5
Explanation:
One set of optimal operations is as follows:
1. Choose i = 1, and nums becomes [4,6,1,6].
2. Choose i = 3, and nums becomes [4,6,2,5].
3. Choose i = 1, and nums becomes [5,5,2,5].
The maximum integer of nums is 5. It can be shown that the maximum number cannot be less than 5.
Therefore, we return 5.

Example 2:
Input: nums = [10,1]
Output: 10
Explanation:
It is optimal to leave nums as is, and since 10 is the maximum value, we return 10.

Constraints:
    n == nums.length
    2 <= n <= 10^5
    0 <= nums[i] <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

/*
    TC: O(Nlog(max of nums)) = O(Nlog(1e9))
    SC: O(1)
*/
class Solution_BinarySearch
{
public:
    bool isValid(int x, vector<int> &nums)
    {
        long sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum > (long)x * (i + 1))
                return false;
        }
        return true;
    }

    int minimizeArrayValue(vector<int> &nums)
    {
        int left = 0, right = *max_element(nums.begin(), nums.end());
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (isValid(mid, nums))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

/*
    TC: O(N)
    SC: O(1)
*/
class Solution_PrefixSum_Average
{
public:
    int minimizeArrayValue(vector<int> &nums)
    {
        long sum = 0, maxAvg = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            maxAvg = max(maxAvg, (sum + i) / (i + 1));
        }
        return maxAvg;
    }
};