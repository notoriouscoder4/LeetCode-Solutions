/*
You have two fruit baskets containing n fruits each.
You are given two 0-indexed integer arrays basket1 and basket2 representing the cost of fruit in each basket.
You want to make both baskets equal. To do so, you can use the following operation as many times as you want:

1.  Chose two indices i and j, and swap the ith fruit of basket1 with the jth fruit of basket2.
2.  The cost of the swap is min(basket1[i],basket2[j]).

Two baskets are considered equal if sorting them according to the fruit cost makes them exactly the same baskets.

Return the minimum cost to make both the baskets equal or -1 if impossible.

Example 1:
Input: basket1 = [4,2,2,2], basket2 = [1,4,1,2]
Output: 1
Explanation: Swap index 1 of basket1 with index 0 of basket2, which has cost 1. Now basket1 = [4,1,2,2] and basket2 = [2,4,1,2]. Rearranging both the arrays makes them equal.

Example 2:
Input: basket1 = [2,3,4,1], basket2 = [3,2,5,1]
Output: -1
Explanation: It can be shown that it is impossible to make both the baskets equal.

Constraints:
    basket1.length == bakste2.length
    1 <= basket1.length <= 10^5
    1 <= basket1[i],basket2[i] <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

/*
Complexity:
    Time complexity: O(nlog⁡n)

    Space complexity: O(n)
*/
class Solution
{
public:
    long long minCost(vector<int> &basket1, vector<int> &basket2)
    {
        unordered_map<int, int> c1, c2;
        int minval = basket1[0];

        for (int i = 0; i < basket1.size(); i++)
        {
            c1[basket1[i]]++;
            minval = min(minval, basket1[i]);
            c2[basket2[i]]++;
            minval = min(minval, basket2[i]);
        }

        vector<int> toSwap;

        for (auto it : c1)
        {
            int cost = it.first;
            int occ1 = it.second, occ2 = c2[it.first];
            int diff = abs(occ1 - occ2);
            if (diff % 2 == 1) // it means we can't swap and rearrange the baskets
            {
                return -1;
            }
            diff = diff / 2;
            while (diff--)
                toSwap.push_back(cost);
            c1[cost] = 0;
            c2[cost] = 0;
        }

        for (auto it : c2)
        {
            int cost = it.first;
            int occ1 = c1[it.first], occ2 = it.second;
            int diff = abs(occ1 - occ2);
            if (diff % 2 == 1) // it means we can't swap and rearrange the baskets
            {
                return -1;
            }
            diff = diff / 2;
            while (diff--)
                toSwap.push_back(cost);
            c1[cost] = 0;
            c2[cost] = 0;
        }

        sort(toSwap.begin(), toSwap.end());
        long long ans = 0;
        for (int i = 0; i < toSwap.size() / 2; i++)
        {
            ans += min(2ll * minval, 1ll * toSwap[i]);
        }
        return ans;
    }
};