/*
Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths.
If it is impossible to form any triangle of a non-zero area, return 0.

Example 1:
Input: nums = [2,1,2]
Output: 5

Example 2:
Input: nums = [1,2,1]
Output: 0

Constraints:
3 <= nums.length <= 10^4
1 <= nums[i] <= 10^6
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
      int largestPerimeter(vector<int> &nums)
      {
            int n = nums.size();
            sort(nums.begin(), nums.end());
            for (int i = n - 1; i > 1; --i)
            {
                  if (nums[i] < nums[i - 1] + nums[i - 2])
                        return nums[i] + nums[i - 1] + nums[i - 2];
            }
            return 0;
      }
};

int main()
{
      vector<int> nums = {2, 1, 2};
      Solution obj;
      int ans = obj.largestPerimeter(nums);
      cout << "The largest Perimeter of Triangle: " << ans << "\n";
      return 0;
}