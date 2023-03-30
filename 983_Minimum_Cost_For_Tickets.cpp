/*
You have planned some train traveling one year in advance.
The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.


Example 1:
Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel.

Example 2:
Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total, you spent $17 and covered all the days of your travel.

Constraints:
    1 <= days.length <= 365
    1 <= days[i] <= 365
    days is in strictly increasing order.
    costs.length == 3
    1 <= costs[i] <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        vector<int> t(n);
        t[0] = min({costs[0], costs[1], costs[2]});

        for (int i = 1; i < n; i++)
        {
            int last7 = i, last30 = i;
            while (last7 >= 0 && days[last7] + 7 > days[i])
                last7--;
            while (last30 >= 0 && days[last30] + 30 > days[i])
                last30--;

            t[i] = costs[0] + t[i - 1];

            if (last7 != -1)
                t[i] = min(t[i], costs[1] + t[last7]);
            else
                t[i] = min(t[i], costs[1]);

            if (last30 != -1)
                t[i] = min(t[i], costs[2] + t[last30]);
            else
                t[i] = min(t[i], costs[2]);
        }
        return t[n - 1];
    }

    int mincostTickets(vector<int> &days, vector<int> &costs, int cost = 0)
    {
        queue<pair<int, int>> last7, last30;

        for (auto d : days)
        {
            while (!last7.empty() && last7.front().first + 7 <= d)
                last7.pop();
            while (!last30.empty() && last30.front().first + 30 <= d)
                last30.pop();

            last7.push({d, cost + costs[1]});
            last30.push({d, cost + costs[2]});

            cost = min({cost + costs[0], last7.front().second, last30.front().second});
        }
        return cost;
    }
};