/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Constraints:
    0 <= nums.length <= 10^5
    -10^9 <= nums[i] <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Given unsorted array, return length of longest consecutive sequence
    Ex. nums = [100,4,200,1,3,2] -> 4, longest is [1,2,3,4]

    Store in hash set, only check for longer seq if it's the beginning

    Time: O(n)
    Space: O(n)
*/
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;
        for (auto &n : s)
        {
            // if this is the start of the sequence
            // this means that if n=100 and n=n-1=100-1==99 doesn't exist then we can start our series with n
            if (!s.count(n - 1))
            {
                int length = 1;
                while (s.count(n + length))
                    ++length;
                longest = max(longest, length);
            }
        }
        return longest;
    }
};

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    Solution obj;
    auto ans = obj.longestConsecutive(nums);
    cout << ans << "\n";
    return 0;
}