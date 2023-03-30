/*
Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements.
You may return the answer in any order.

Example 1:
Input: nums = [4,6,7,7]
Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]

Example 2:
Input: nums = [4,4,3,2,1]
Output: [[4,4]]

Constraints:
    1 <= nums.length <= 15
    -100 <= nums[i] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void backtrack(vector<int> &nums, int index, vector<int> &sequence, vector<vector<int>> &ans)
    {
        // base case
        if (sequence.size() > 1)
            ans.push_back(sequence);

        // for each backtrack declare unordered_set
        unordered_set<int> set;
        for (int i = index; i < nums.size(); ++i)
        {
            if ((sequence.size() == 0 || sequence.back() <= nums[i]) && (set.find(nums[i]) == set.end()))
            {
                sequence.push_back(nums[i]);
                backtrack(nums, i + 1, sequence, ans);
                sequence.pop_back();
                set.insert(nums[i]);
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> sequence;

        backtrack(nums, 0, sequence, ans);
        return ans;
    }
};

int main()
{
    vector<int> nums = {4, 6, 7, 7};

    Solution obj;
    auto ans = obj.findSubsequences(nums);
    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j < ans[0].size(); ++j)
        {
            cout << ans[i][j];
        }
    }

    return 0;
}