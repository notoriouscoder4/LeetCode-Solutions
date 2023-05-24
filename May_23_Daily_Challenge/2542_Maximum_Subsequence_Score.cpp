/*

*/

#include <bits/stdc++.h>
using namespace std;

class Solution_recursion
{
public:
    long long ans = 0;
    int n;

    void recursion(vector<int> &nums1, vector<int> &nums2, int ind, long long sum, int minn, int k)
    {
        if (k == 0)
        {
            ans = max(ans, sum * minn);
            return;
        }
        if (ind >= n)
            return;
        recursion(nums1, nums2, ind + 1, sum + nums1[ind], min(minn, nums2[ind]), k - 1); // including
        recursion(nums1, nums2, ind + 1, sum, minn, k);                                   // excluding
    }

    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        n = nums1.size();
        for (int i = 0; i < n; i++)
        {
            recursion(nums1, nums2, i, 0, nums2[i], k);
        }
        return ans;
    }
};

/*
    TC: O(nlogn)
    SC: O(n)
*/
class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        long long ans = 0;

        vector<pair<int, int>> v;
        int n = nums1.size();

        for (int i = 0; i < n; i++)
            v.push_back({nums1[i], nums2[i]});

        // Sort pair (nums1[i], nums2[i]) by nums2[i] in decreasing order.
        sort(v.begin(), v.end(), [&](auto const &a, auto const &b)
             { return a.second > b.second; });

        // Use a min-heap to maintain the top k elements.
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        long long sum = 0;

        for (int i = 0; i < k; i++)
        {
            minHeap.push(v[i].first);
            sum += v[i].first;
        }

        // The score of the first k pairs.
        ans = sum * v[k - 1].second;

        // Iterate over every nums2[i] as minimum from nums2.
        for (int i = k; i < n; i++)
        {
            // Remove the smallest integer from the previous top k elements
            // then add nums1[i] to the top k elements.
            long long topp = minHeap.top();
            minHeap.pop();

            sum -= topp;
            sum += v[i].first;
            minHeap.push(v[i].first);

            // Update answer as the maximum score.
            ans = max(ans, sum * v[i].second);
        }
        return ans;
    }
};