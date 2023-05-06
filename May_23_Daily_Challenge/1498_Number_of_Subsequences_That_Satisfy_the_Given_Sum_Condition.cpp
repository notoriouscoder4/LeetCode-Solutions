/*
You are given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target.
Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:
Input: nums = [3,5,6,7], target = 9
Output: 4
Explanation: There are 4 subsequences that satisfy the condition.
[3] -> Min value + max value <= target (3 + 3 <= 9)
[3,5] -> (3 + 5 <= 9)
[3,5,6] -> (3 + 6 <= 9)
[3,6] -> (3 + 6 <= 9)

Example 2:
Input: nums = [3,3,6,8], target = 10
Output: 6
Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
[3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]

Example 3:
Input: nums = [2,3,3,4,6,7], target = 12
Output: 61
Explanation: There are 63 non-empty subsequences, two of them do not satisfy the condition ([6,7], [7]).
Number of valid subsequences (63 - 2 = 61).

Constraints:
    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^6
    1 <= target <= 10^6
*/

#include <bits/stdc++.h>
using namespace std;

/*
Intuition
    Starting from the brute-force approach, if we simply generate all possible subsequences and then iterate through each subsequence to find its maximum and minimum elements,
    this approach is feasible but the time complexity will be very high.

    Assuming the size of the array is n, we will have O(2^n) non-empty subsequences, resulting in a time complexity of O(2^n⋅n).
    This method is very expensive and indicates that we need a more efficient way to traverse the subsequence.

    Note that we only need to consider the minimum and maximum elements of a subsequence to determine whether it is valid,
    and elements with values between them do not affect our judgment.
    Therefore, we can traverse all possible (minimum, maximum) combinations and check if they are valid.

    If there are k subsequences with min as the minimum value and max as the maximum value, we only need to check if min + max <= target.
    The number of such subsequences k depends on how many elements have values that are between min and max.
    Therefore, we need to sort nums first, so that the number of values between min and max can be represented by their index difference.

    Here, we let left and right be the pointers to the minimum element and the maximum element. That is nums[left] = min.

    Now we need to traverse each possible minimum value.
    For min = nums[left], we need to ensure that the subsequences with this number as the minimum value are valid,
    which means the maximum element of these subsequences cannot be greater than target-nums[left].
    In other words, we need to find the largest element that is not greater than target-nums[left].

    Since the array is already sorted, we can use binary search to find the insertion position of target - nums[left].
    Note that we are looking for the rightmost element that is smaller than or equal to target - nums[left],
    and the binary search finds the index of the smallest element that is larger than target - nums[left].
    Therefore, once we find the rightmost insertion position as k, we have right = k - 1.

    Now we have the left and right indices left and right. For each number in the range [left + 1, right],
    there are 2 options: we can either take it or not take it, so there are a total of 2^(right - left) valid subsequences that have nums[left] as the minimum element.

    Next, we move to the next min by moving the left pointer left one step to the right.
    We repeat the process by using binary search to find the new insertion position of target - nums[left].

    Sometimes we may encounter situations where left > right and we don't need to consider these subsequences because they have already been calculated before and there is no need to recalculate them again.



Algorithm
    1. Initialize answer = 0 and the length of nums as n.

    2. Iterate over the left index left from 0 to n - 1, for each index left:

        2a. Use binary search to locate the rightmost index right which nums[right] <= target - nums[left].
        2b. If left <= right, count the total number of valid subsequences as 2^(right - left)
        2c. Increment answer by the number of valid subsequences.
    3. Return answer once the iteration ends.
*/

/*
    TC: O(NlogN)
    SC: O(N)
*/
class Solution_BinarySearch
{
public:
    int binarySearchRightmost(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }

    int numSubseq(vector<int> &nums, int target)
    {
        int n = nums.size();
        int mod = 1e9 + 7;
        sort(nums.begin(), nums.end());

        vector<int> power(n);
        power[0] = 1;
        for (int i = 1; i < n; i++)
            power[i] = (power[i - 1] * 2) % mod;

        int ans = 0;
        for (int left = 0; left < n; left++)
        {
            int right = binarySearchRightmost(nums, target - nums[left]) - 1;
            if (right >= left)
            {
                ans += power[right - left];
                ans %= mod;
            }
        }
        return ans;
    }
};

/*
Intuition
    Recalling the binary search in the previous solution, we traverse left from 0 to n - 1, so the value of target - nums[left] actually decreases,
    which means the insertion position of target - nums[left] in the array also decreases.

    Therefore, we do not bother applying binary search, but only need to set another pointer right for the largest element which is smaller than or equal to target - nums[left].
    In the process of traversing left, the pointer right is monotonically moving to the left, and the time complexity of the algorithm post-sort is only O(n) instead of O(n⋅log⁡n) in the previous approach (although the overall time complexity will not change due to the sort).

Algorithm
    1. Initialize answer = 0 and the length of nums as n. Set two pointers left = 0 and right = n - 1.

    2. Iterate over left while left <= right, for each index left:

        2a. If nums[left] + nums[right] > target, it means nums[right] is too large for the right boundary,
        we shall move it to the left by setting right = right - 1.

        2b. Otherwise, right is the rightmost index which nums[right] <= target - nums[left], we can count the total number of valid subsequences as 2^(right - left)  and increment answer by this number.

    Repeat step 2.

    3. Return answer once the iteration ends.
*/

/*
    TC: O(NlogN)
    SC: O(N)
*/
class Solution_TwoPointers
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        int n = nums.size();
        int mod = 1e9 + 7;
        sort(nums.begin(), nums.end());

        vector<int> power(n);
        power[0] = 1;
        for (int i = 1; i < n; i++)
            power[i] = (power[i - 1] * 2) % mod;

        int ans = 0;
        int left = 0, right = n - 1;

        while (left <= right)
        {
            if (nums[left] + nums[right] <= target)
            {
                ans += power[right - left];
                ans %= mod;
                left++;
            }
            else
            {
                right--;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {3, 5, 6, 7};
    int target = 9;

    Solution_TwoPointers obj;
    auto ans = obj.numSubseq(nums, target);
    cout << ans << endl;

    return 0;
}