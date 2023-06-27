/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

Example 1:
Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

Example 2:
Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

Example 3:
Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [[1,3],[2,3]]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]


Constraints:
    1 <= nums1.length, nums2.length <= 10^5
    -10^9 <= nums1[i], nums2[i] <= 10^9
    nums1 and nums2 both are sorted in ascending order.
    1 <= k <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

/*
    TC: O(min(k.logk, m.n.log(m.n)))
        . We iterate O(min⁡(k,m.n)) times to get the required number of pairs.
        . The visited set and heap both can grow up to a size of O(min⁡(k,m.n)) because at each iteration we are inserting at most two pairs and popping one pair.
        Insertions into a min-heap take an additional log⁡\loglog factor.
        So, to insert O(min⁡(k,m.n)) elements into minHeap, we need O(min⁡(k.log⁡k,m.n.log⁡(m.n)) time.
        . The visited set takes on an average constant time and hence will take O(min⁡(k,m.n)) time in major languages like Java and Python except in C++ where it would also take O(min⁡(k.log⁡k,m.n.log⁡(m.n))) because we used ordered_set that keeps the values in sorted order.

    SC: O(min(k, m.n))
        . The visited set and heap can both grow up to a size of O(min⁡(k,m⋅n)) because at each iteration we are inserting at most two pairs and popping one pair.
*/
class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int m = nums1.size(), n = nums2.size();

        vector<vector<int>> ans;
        set<pair<int, int>> visited;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        minHeap.push({nums1[0] + nums2[0], {0, 0}});
        visited.insert({0, 0});

        while (k-- && !minHeap.empty())
        {
            auto top = minHeap.top();
            minHeap.pop();
            int i = top.second.first;
            int j = top.second.second;

            ans.push_back({nums1[i], nums2[j]});

            if (i + 1 < m && visited.find({i + 1, j}) == visited.end())
            {
                minHeap.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }

            if (j + 1 < n && visited.find({i, j + 1}) == visited.end())
            {
                minHeap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }
        }
        return ans;
    }
};