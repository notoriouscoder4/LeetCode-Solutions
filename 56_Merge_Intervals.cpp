/*
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        if (n == 1)
            return intervals;

        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b)
             { return a[0] < b[0]; });

        vector<vector<int>> ans;

        int i = 0;
        while (i < n - 1)
        {
            // merging
            if (intervals[i][1] >= intervals[i + 1][0])
            {
                intervals[i + 1][0] = intervals[i][0];
                intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
            i++;
        }
        ans.push_back(intervals[i]);

        return ans;
    }
};