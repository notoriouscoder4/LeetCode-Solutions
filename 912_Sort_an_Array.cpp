/*
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

Example 1:
Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

Example 2:
Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.

Constraints:
    1 <= nums.length <= 5 * 10^4
    -5 * 104 <= nums[i] <= 5 * 10^4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums, int start, int mid, int end)
    {
        int temp[end - start + 1];
        int i = start, j = mid + 1, k = 0;

        while (i <= mid && j <= end)
        {
            if (nums[i] < nums[j])
            {
                temp[k] = nums[i];
                i++;
            }
            else
            {
                temp[k] = nums[j];
                j++;
            }
            k++;
        }
        while (i <= mid)
        {
            temp[k] = nums[i];
            i++;
            k++;
        }
        while (j <= end)
        {
            temp[k] = nums[j];
            j++;
            k++;
        }
        for (i = start; i <= end; i++)
            nums[i] = temp[i - start];
    }

    void mergeSort(vector<int> &nums, int start, int end)
    {
        if (start < end)
        {
            int mid = (start + end) / 2;
            mergeSort(nums, start, mid);
            mergeSort(nums, mid + 1, end);
            merge(nums, start, mid, end);
        }
    }

    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return nums;
    }
};

int main()
{
    vector<int> nums = {5, 2, 3, 1};

    Solution obj;
    auto ans = obj.sortArray(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}