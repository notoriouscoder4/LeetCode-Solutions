/*
You are given two 0-indexed arrays nums and cost consisting each of n positive integers.

You can do the following operation any number of times:

Increase or decrease any element of the array nums by 1.

The cost of doing one operation on the ith element is cost[i].

Return the minimum total cost such that all the elements of the array nums become equal.

Example 1:
Input: nums = [1,3,5,2], cost = [2,3,1,14]
Output: 8
Explanation: We can make all the elements equal to 2 in the following way:
- Increase the 0th element one time. The cost is 2.
- Decrease the 1st element one time. The cost is 3.
- Decrease the 2nd element three times. The cost is 1 + 1 + 1 = 3.
The total cost is 2 + 3 + 3 = 8.
It can be shown that we cannot make the array equal with a smaller cost.

Example 2:
Input: nums = [2,2,2,2,2], cost = [4,2,8,1,3]
Output: 0
Explanation: All the elements are already equal, so no operations are needed.

Constraints:
    n == nums.length == cost.length
    1 <= n <= 10^5
    1 <= nums[i], cost[i] <= 10^6
*/

#include <bits/stdc++.h>
using namespace std;

/*
    TC: O(NLogK)
    SC: O(1)
*/
class Solution_Binary_Search
{
public:
    // Get the cost of making every element equals base.
    long long getCost(vector<int> &nums, vector<int> &cost, int base)
    {
        long long result = 0;
        for (int i = 0; i < nums.size(); ++i)
            result += 1L * abs(nums[i] - base) * cost[i];
        return result;
    }

    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        // Initialize the left and the right boundary of the binary search.
        long long answer = getCost(nums, cost, nums[0]);
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());

        // As shown in the previous picture, if F(mid) > F(mid + 1), then the minimum
        // is to the right of mid, otherwise, the minimum is to the left of mid.
        while (left < right)
        {
            int mid = (left + right) / 2;
            long long cost1 = getCost(nums, cost, mid);
            long long cost2 = getCost(nums, cost, mid + 1);
            answer = min(cost1, cost2);
            if (cost1 > cost2)
                left = mid + 1;
            else
                right = mid;
        }
        return answer;
    }
};