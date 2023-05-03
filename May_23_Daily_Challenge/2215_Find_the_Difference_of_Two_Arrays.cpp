/*
Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

    1. answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
    2. answer[1] is a list of all distinct integers in nums2 which are not present in nums1.

Note that the integers in the lists may be returned in any order.

Example 1:
Input: nums1 = [1,2,3], nums2 = [2,4,6]l̥
Output: [[1,3],[4,6]]
Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].

Example 2:
Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
Output: [[3],[]]
Explanation:
For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].

Constraints:
    1 <= nums1.length, nums2.length <= 1000
    -1000 <= nums1[i], nums2[i] <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Time complexity: O(N+M)
    Space complexity: O(max(N,M))
*/
class Solution_hashset
{
public:
    vector<int> getElementsOnlyInFirstList(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> onlyInNums1;

        // Store nums2 elements in an unordered set.
        unordered_set<int> existsInNums2;
        for (int num : nums2)
            existsInNums2.insert(num);

        // Iterate over each element in the list nums1.
        for (int num : nums1)
        {
            if (existsInNums2.find(num) == existsInNums2.end())
                onlyInNums1.insert(num);
        }

        // Convert to vector.
        return vector<int>(onlyInNums1.begin(), onlyInNums1.end());
    }

    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        return {getElementsOnlyInFirstList(nums1, nums2), getElementsOnlyInFirstList(nums2, nums1)};
    }
};

/*
    Time complexity: O(N∗M)
        In the first call to getElementsOnlyInFirstList, we iterate over the first list and, for each element,
        iterate over the second, which costs us N∗M operations. Then again, doing it for the other pair (nums2, nums1),
        the total operations will be M∗N.
        Hence the total time complexity would be O(N∗M).

    Space complexity: O(1)
        The only space required (two lists of size N and M) is to store the output list that is not considered part of the space complexity.
        Hence, the total space complexity would be constant.
*/
class Solution_brute_force
{
public:
    // Returns the elements in the first arg nums1 that don't exist in the second arg nums2.
    vector<int> getElementsOnlyInFirstList(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> onlyInNums1;

        // Iterate over each element in the list nums1.
        for (int num : nums1)
        {
            bool existInNums2 = false;
            // Check if num is present in the second arg nums2.
            for (int x : nums2)
            {
                if (x == num)
                {
                    existInNums2 = true;
                    break;
                }
            }

            if (!existInNums2)
            {
                onlyInNums1.insert(num);
            }
        }

        // Convert to vector.
        return vector<int>(onlyInNums1.begin(), onlyInNums1.end());
    }

    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        return {getElementsOnlyInFirstList(nums1, nums2), getElementsOnlyInFirstList(nums2, nums1)};
    }
};

int main()
{
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};

    Solution_hashset obj;
    auto ans = obj.findDifference(nums1, nums2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << ",";
        }
        cout << "]";
    }
    return 0;
}