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

/*
Approach -2

    -We start by defining the topKFrequent function that takes a vector of integers nums and an integer k as input,
    and returns a vector of integers as output.

    -We use a map container to count the frequency of each element in the input vector.
    The keys of the map represent the elements in the vector, and the values represent their frequencies.

    -We define a lambda function cmp that compares two pairs of integers based on their second element (i.e., their frequency).
    This function is used to define a priority queue that keeps track of the k most frequent elements in the map.

    -We create a priority queue of pairs of integers, with the first element representing the key (i.e., the element in the input vector) and the second element representing its frequency.
    We use the cmp function as the comparison function for the priority queue.

    -We iterate over the map using a range-based for loop, and push each pair of key-value into the priority queue.

    -If the size of the priority queue exceeds k, we remove the least frequent element by calling pop().

    -Once we have processed all elements in the map, we extract the k most frequent elements from the priority queue and store their keys (i.e., the elements in the input vector) in a vector.

    -We return the vector of k most frequent elements as output.

Complexity
    Time complexity: O(Nlog N)

    Space complexity: O(N)
*/
class Solution_min_heap
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        map<int, int> freq;
        for (int num : nums)
        {
            freq[num]++;
        }

        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b)
        {
            return a.second < b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for (const auto &p : freq)
        {
            pq.push(p);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<int> result;
        while (!pq.empty())
        {
            result.push_back(pq.top().first);
            pq.pop();
        }

        return result;
    }
};