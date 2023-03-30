/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Example 1:
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]

Example 2:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Constraints:
    1 <= nums.length <= 8
    -10 <= nums[i] <= 10
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void backtrack(vector<int> &nums, int i, vector<vector<int>> &ans)
    {
        if (i == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> s;
        for (int j = i; j < nums.size(); j++)
        {
            if (s.find(nums[j]) != s.end())
                continue;
            s.insert(nums[j]);
            swap(nums[i], nums[j]);
            backtrack(nums, i + 1, ans);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;

        backtrack(nums, 0, ans);
        return ans;
    }
};