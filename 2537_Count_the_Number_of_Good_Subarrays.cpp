/*
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A subarray arr is good if it there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1,1,1], k = 10
Output: 1
Explanation: The only good subarray is the array nums itself.

Example 2:
Input: nums = [3,1,4,3,2,2,4], k = 2
Output: 4
Explanation: There are 4 different good subarrays:
- [3,1,4,3,2,2] that has 2 pairs.
- [3,1,4,3,2,2,4] that has 3 pairs.
- [1,4,3,2,2,4] that has 2 pairs.
- [4,3,2,2,4] that has 2 pairs.

Constraints:
    1 <= nums.length <= 10^5
    1 <= nums[i], k <= 10^9
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countGood(vector<int> &nums, int k)
    {
        long long good = 0;
        long long pairs = 0;
        unordered_map<int, int> mp;
        int i = 0, j = 0;

        while (j < nums.size())
        {
            mp[nums[j]]++;
            pairs = pairs + (mp[nums[j]] - 1);

            if (pairs >= k)
            {
                while (i <= j && pairs >= k)
                {
                    good = good + (nums.size() - j);
                    mp[nums[i]]--;
                    pairs = pairs - (mp[nums[i]]);
                    if (mp[nums[i]] == 0)
                        mp.erase(nums[i]);
                    i++;
                }
            }
            j++;
        }
        return good;
    }
};

int main()
{
    vector<int> nums = {3, 1, 4, 3, 2, 2, 4};
    int k = 2;

    Solution obj;
    auto ans = obj.countGood(nums, k);
    cout << ans << "\n";

    return 0;
}