/*
Given a wooden stick of length n units. The stick is labelled from 0 to n.
For example, a stick of length 6 is labelled as follows:


Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts.
When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut).

Please refer to the first example for a better explanation.

Return the minimum total cost of the cuts.

Example 1:
Input: n = 7, cuts = [1,3,4,5]
Output: 16
Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:

The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the second part of the first cut), the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.
Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).

Example 2:
Input: n = 9, cuts = [5,6,1,4,2]
Output: 22
Explanation: If you try the given cuts ordering the cost will be 25.
There are much ordering with total cost <= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which is the minimum possible.

Constraints:
    2 <= n <= 10^6
    1 <= cuts.length <= min(n - 1, 100)
    1 <= cuts[i] <= n - 1
    All the integers in cuts array are distinct.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution_recursion
{
public:
    int solve(int start_stick, int end_stick, vector<int> &cuts, int left, int right)
    {
        if (left > right)
            return 0;

        int cost = 1e9;
        for (int i = left; i <= right; i++)
        {
            int left_cost = solve(start_stick, cuts[i], cuts, left, i - 1);
            int right_cost = solve(cuts[i], end_stick, cuts, i + 1, right);
            int curr_cost = (end_stick - start_stick) + left_cost + right_cost;
            cost = min(cost, curr_cost);
        }
        return cost;
    }

    int minCost(int n, vector<int> &cuts)
    {
        sort(cuts.begin(), cuts.end());
        return solve(0, n, cuts, 0, cuts.size() - 1);
    }
};

class Solution_memoization
{
public:
    int t[101][101];
    int solve(int start_stick, int end_stick, vector<int> &cuts, int left, int right)
    {
        if (left > right)
            return 0;

        if (t[left][right] != -1)
            return t[left][right];

        int cost = 1e9;
        for (int i = left; i <= right; i++)
        {
            int left_cost = solve(start_stick, cuts[i], cuts, left, i - 1);
            int right_cost = solve(cuts[i], end_stick, cuts, i + 1, right);
            int curr_cost = (end_stick - start_stick) + left_cost + right_cost;
            cost = min(cost, curr_cost);
        }
        return t[left][right] = cost;
    }

    int minCost(int n, vector<int> &cuts)
    {
        memset(t, -1, sizeof(t));
        sort(cuts.begin(), cuts.end());
        return solve(0, n, cuts, 0, cuts.size() - 1);
    }
};

class Solution_memoization_optimized
{
public:
    int t[102][102];
    int solve(vector<int> &cuts, int left, int right)
    {
        if (right - left <= 1)
            return 0;

        if (t[left][right] != -1)
            return t[left][right];

        int cost = 1e9;
        for (int i = left + 1; i <= right - 1; i++)
        {
            int left_cost = solve(cuts, left, i);
            int right_cost = solve(cuts, i, right);
            int curr_cost = (cuts[right] - cuts[left]) + left_cost + right_cost;
            cost = min(cost, curr_cost);
        }
        return t[left][right] = cost;
    }

    int minCost(int n, vector<int> &cuts)
    {
        memset(t, -1, sizeof(t));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        return solve(cuts, 0, cuts.size() - 1);
    }
};

class Solution_tabulation
{
public:
    int t[102][102];
    int minCost(int n, vector<int> &cuts)
    {
        memset(t, -0, sizeof(t));
        sort(cuts.begin(), cuts.end());
        cuts.push_back(0);
        cuts.push_back(n);

        for (int left = cuts.size() - 1; left >= 0; left--)
        {
            for (int right = left + 1; right < cuts.size(); right++)
            {
                for (int i = left + 1; i < right; i++)
                {
                    int curr_cost = (cuts[right] - cuts[left]) + t[left][i] + t[i][right];
                    t[left][right] = min(t[left][right] == 0 ? INT_MAX : t[left][right], curr_cost);
                }
            }
        }
        return t[0][cuts.size() - 1];
    }
};