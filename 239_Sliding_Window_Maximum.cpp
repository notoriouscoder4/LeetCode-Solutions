/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:
Input: nums = [1], k = 1
Output: [1]

Constraints:
    1 <= nums.length <= 10^5
    -10^4 <= nums[i] <= 10^4
    1 <= k <= nums.length
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        if (k > nums.size())
        {
            ans.push_back(*max_element(nums.begin(), nums.end()));
            return ans;
        }

        deque<int> dq;
        int i = 0, j = 0;
        while (j < nums.size())
        {
            while (!dq.empty() && dq.back() < nums[j])
                dq.pop_back();
            dq.push_back(nums[j]);

            if (j - i + 1 < k)
            {
                j++;
            }
            else if (j - i + 1 == k)
            {
                ans.push_back(dq.front());
                if (dq.front() == nums[i])
                    dq.pop_front();
                i++;
                j++;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    Solution obj;
    auto ans = obj.maxSlidingWindow(nums, k);
    for (auto it : ans)
        cout << it << " ";

    return 0;
}