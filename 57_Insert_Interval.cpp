/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi]
represent the start and the end of the ith interval and intervals is sorted in ascending order by starti.
You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order
by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

Constraints:
    0 <= intervals.length <= 10^4
    intervals[i].length == 2
    0 <= starti <= endi <= 105
    intervals is sorted by starti in ascending order.
    newInterval.length == 2
    0 <= start <= end <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Given array of non-overlapping intervals & a new interval, insert & merge if necessary
    Ex. intervals = [[1,3],[6,9]], newInterval = [2,5] -> [[1,5],[6,9]]

    To merge: while intervals are still overlapping the new one, take the larger bounds

    Time: O(n)
    Space: O(n)
*/
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;

        // 2 cases.
        for (auto &currentInterval : intervals)
        {
            // case 1 : non-overlapping
            // new interval is after current interval, add current interval to the ans.
            if (currentInterval[1] < newInterval[0])
                ans.push_back(currentInterval);

            // if new interval comes before current interval that means we need to make it current interval and check for overlapping with others.
            // And our current interval will also be add to ans.
            else if (newInterval[1] < currentInterval[0])
            {
                ans.push_back(newInterval);
                // update it to current interval for overlapping checking
                newInterval = currentInterval;
            }
            // case 2 : overlapping
            else
            {
                // update the new interval for checking overlapping.
                newInterval[0] = min(currentInterval[0], newInterval[0]);
                newInterval[1] = max(currentInterval[1], newInterval[1]);
            }
        }
        // Add the last non-overlapping interval (newInterval)
        ans.push_back(newInterval);

        return ans;
    }
};

int main()
{
    vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval = {4, 8};

    Solution obj;
    auto ans = obj.insert(intervals, newInterval);
    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j < ans[0].size(); ++j)
        {
            cout << ans[i][j] << ",";
        }
        cout << " ";
    }

    return 0;
}