/*
You are given three positive integers: n, index, and maxSum.
You want to construct an array nums (0-indexed) that satisfies the following conditions:

. nums.length == n
. nums[i] is a positive integer where 0 <= i < n.
. abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
. The sum of all the elements of nums does not exceed maxSum.
. nums[index] is maximized.

Return nums[index] of the constructed array.

Note that abs(x) equals x if x >= 0, and -x otherwise.

Example 1:
Input: n = 4, index = 2,  maxSum = 6
Output: 2
Explanation: nums = [1,2,2,1] is one array that satisfies all the conditions.
There are no arrays that satisfy all the conditions and have nums[2] == 3, so 2 is the maximum nums[2].

Example 2:
Input: n = 6, index = 1,  maxSum = 10
Output: 3

Constraints:
    1 <= n <= maxSum <= 10^9
    0 <= index < n
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long calc(long n) // sum of numbers from [1 to n]
    {
        return ((n * (n + 1)) / 2);
    }

    long getSum(int totalLen, int val)
    {
        long totalSum = 0;
        int decreasingLen = val; // count of decreasing elements [val, val - 1, .., 1]

        //[val, val - 1, val - 2, ... 1, 1, 1, 1]
        if (totalLen >= decreasingLen)
        {
            long currSum = calc(val);
            int remainingSum = totalLen - decreasingLen; // all 1's
            totalSum = currSum + remainingSum;
        }
        else //[val, val - 1, val - 2]
        {
            long lastVal = decreasingLen - totalLen;
            totalSum = calc(val) - calc(lastVal);
        }
        return totalSum;
    }
    
    int maxValue(int n, int index, int maxSum)
    {
        int low = 1, high = maxSum;
        int leftCount = index, rightCount = n - index - 1;
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            //=====================================================
            long leftSum = getSum(leftCount, mid - 1);
            long rightSum = getSum(rightCount, mid - 1);
            long totalSum = leftSum + mid + rightSum;
            //=======================================================
            if (totalSum > maxSum)
                high = mid - 1;
            else
            {
                ans = mid;
                low = mid + 1;
            }
        }
        return ans;
    }
};