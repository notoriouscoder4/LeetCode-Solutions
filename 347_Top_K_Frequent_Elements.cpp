/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Constraints:
    1 <= nums.length <= 10^5
    -10^4 <= nums[i] <= 10^4
    k is in the range [1, the number of unique elements in the array].
    It is guaranteed that the answer is unique.


Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Given an integer array nums & an integer k, return the k most frequent elements
    Ex. nums = [1,1,1,2,2,3] k = 2 -> [1,2], nums = [1] k = 1 -> [1]

    Heap -> optimize w/ freq map & bucket sort (no freq can be > n), get results from end
*/

/*
    Time: O(n log k)
    Space: O(n + k)
*/
// class Solution
// {
// public:
//     vector<int> topKFrequent(vector<int> &nums, int k)
//     {
//         unordered_map<int, int> m;
//         for (int i = 0; i < nums.size(); i++)
//             m[nums[i]]++;

//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> max_heap;
//         for (auto it = m.begin(); it != m.end(); it++)
//         {
//             max_heap.push({it->second, it->first});
//             if (max_heap.size() > k)
//                 max_heap.pop();
//         }

//         vector<int> result;
//         while (!max_heap.empty())
//         {
//             result.push_back(max_heap.top().second);
//             max_heap.pop();
//         }
//         return result;
//     }
// };

/*
    Time: O(n)
    Space: O(n)
*/

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();

        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
            m[nums[i]]++;

        vector<vector<int>> buckets(n + 1);
        for (auto it = m.begin(); it != m.end(); it++)
            buckets[it->second].push_back(it->first);

        vector<int> result;
        for (int i = n; i >= 0; i--)
        {
            if (result.size() >= k)
                break;
            if (!buckets[i].empty())
                result.insert(result.end(), buckets[i].begin(), buckets[i].end());
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    Solution obj;
    auto ans = obj.topKFrequent(nums, k);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    return 0;
}