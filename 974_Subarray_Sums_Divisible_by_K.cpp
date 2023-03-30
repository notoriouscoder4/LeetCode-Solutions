/*
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

Example 1:
Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

Example 2:
Input: nums = [5], k = 9
Output: 0

Constraints:
    1 <= nums.length <= 3 * 10^4
    -10^4 <= nums[i] <= 10^4
    2 <= k <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        // map of key = remainder after divided by k, value = count of remainder
        unordered_map<int, int> mp;

        int currentSum = 0;
        int count = 0;
        mp[0]++;

        for (auto x : nums)
        {
            currentSum += x;
            int mod = (currentSum % k + k) % k;

            // check if mod already present
            if (mp.find(mod) != mp.end())
                count += mp[mod];
            mp[mod]++;
        }
        return count;
    }
};