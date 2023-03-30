/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

Constraints:
    3 <= nums.length <= 3000
    -10^5 <= nums[i] <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Given int array, return all unique triplets that sum to 0
    Ex. nums = [-1,0,1,2,-1,-4] -> [[-1,-1,2],[-1,0,1]]

    Sort, for each i, have j & k go outside in, check for 0 sums

    since we know that, a + b + c = 0, so what if I keep 'a' as constant so in that way I will get b + c = -a;
    So I can find b and c using the two pointer technique, and I will get my triplets.
    So 'a' will point to first element of sorted array i.e. a = nums[0] and
    j pointer will point to extreme left of sorted array i.e. j = i + 1, and
    k pointer will point to extreme right of sorted array i.e. k = nums.size() - 1

    Time: O(n^2)
    Space: O(n)
*/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;

        int n = nums.size();
        if (n < 3)
            return result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i)
        {
            if (nums[i] > 0)
                break;

            // ignoring duplicates
            if (i > 0 && nums[i - 1] == nums[i])
                continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                    j++;
                else if (sum > 0)
                    k--;
                else
                {
                    result.push_back({nums[i], nums[j], nums[k]});

                    while (j < k && nums[j] == nums[j + 1])
                        j++;
                    j++;

                    while (j < k && nums[k - 1] == nums[k])
                        k--;
                    k--;
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution obj;
    auto ans = obj.threeSum(nums);
    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j < ans[i].size(); ++j)
            cout << ans[i][j] << " ";
        cout << ", ";
    }
    return 0;
}