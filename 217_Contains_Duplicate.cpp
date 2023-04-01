/*
Given an integer array nums, return true if any value appears at least twice in the array,
and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

Constraints:
      1 <= nums.length <= 10^5
      -10^9 <= nums[i] <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
      /*
            TC: O(NlogN)
            SC: O(1)
      */
      bool containsDuplicate_sorting(vector<int> &nums)
      {
            sort(nums.begin(), nums.end());
            for (int i = 1; i < nums.size(); ++i)
            {
                  if (nums[i] == nums[i - 1])
                        return true;
            }
            return false;
      }

      /*
            TC: O(N)
            SC: O(N)
      */
      bool containsDuplicate_hashset(vector<int> &nums)
      {
            unordered_set<int> s;

            for (int i = 0; i < nums.size(); ++i)
            {
                  if (s.find(nums[i]) != s.end())
                        return true;
                  s.insert(nums[i]);
            }
            return false;
      }

      /*
            TC: O(N)
            SC: O(N)
      */
      bool containsDuplicate_hashmap(vector<int> &nums)
      {
            unordered_map<int, int> mp;

            for (int i = 0; i < nums.size(); ++i)
            {
                  if (mp.find(nums[i]) != mp.end())
                        return true;
                  mp[nums[i]]++;
            }
            return false;
      }
};

int main()
{
      vector<int> nums{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

      Solution obj;
      auto containDuplicate = obj.containsDuplicate_hashmap(nums);
      cout << containDuplicate << "\n";

      return 0;
}
