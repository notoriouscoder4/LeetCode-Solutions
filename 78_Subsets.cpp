/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

Constraints:
    1 <= nums.length <= 10
    -10 <= nums[i] <= 10
    All the numbers of nums are unique.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void backtrack(vector<int> &nums, int n, int ind, vector<int> &ds, vector<vector<int>> &ans)
    {
        if (ind == n)
        {
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[ind]);
        backtrack(nums, n, ind + 1, ds, ans);
        ds.pop_back();
        backtrack(nums, n, ind + 1, ds, ans);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> ds;

        backtrack(nums, n, 0, ds, ans);
        return ans;
    }
};