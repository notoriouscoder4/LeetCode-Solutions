/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]

Constraints:
    1 <= candidates.length <= 100
    1 <= candidates[i] <= 50
    1 <= target <= 30
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void backtrack(vector<int> &nums, int ind, int target, vector<int> &ds, vector<vector<int>> &ans)
    {
        if (target < 0)
        {
            return;
        }
        else if (target == 0)
        {
            ans.push_back(ds);
        }

        else
        {
            for (int i = ind; i < nums.size(); i++)
            {
                if (i > ind && nums[i] == nums[i - 1]) // for checking it do not pick the previous element again
                    continue;

                int pick = nums[i];
                ds.push_back(pick);
                backtrack(nums, i + 1, target - pick, ds, ans);
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;

        sort(candidates.begin(), candidates.end());

        backtrack(candidates, 0, target, ds, ans);
        return ans;
    }
};