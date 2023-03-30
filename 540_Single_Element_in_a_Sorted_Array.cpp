/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

Example 1:
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: nums = [3,3,7,7,10,11,11]
Output: 10

Constraints:
    1 <= nums.length <= 10^5
    0 <= nums[i] <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        int start = 0;
        int end = n - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (mid == 0 && nums[mid] != nums[mid + 1])
                return nums[mid];
            else if (mid == n - 1 && nums[mid] != nums[n - 2])
                return nums[mid];
            else if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];
            else if (mid % 2 == 0)
            {
                if (nums[mid] == nums[mid + 1])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
            else
            {
                if (nums[mid] == nums[mid + 1])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }
        return -1;
    }
};