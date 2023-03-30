/*
Given a data stream input of non-negative integers a1, a2, ..., an, summarize the numbers seen so far as a list of disjoint intervals.

Implement the SummaryRanges class:

SummaryRanges() Initializes the object with an empty stream.
void addNum(int value) Adds the integer value to the stream.
int[][] getIntervals() Returns a summary of the integers in the stream currently as a list of disjoint intervals [starti, endi].
The answer should be sorted by starti.

Example 1:
Input
["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals"]
[[], [1], [], [3], [], [7], [], [2], [], [6], []]
Output
[null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]
Explanation
SummaryRanges summaryRanges = new SummaryRanges();
summaryRanges.addNum(1);      // arr = [1]
summaryRanges.getIntervals(); // return [[1, 1]]
summaryRanges.addNum(3);      // arr = [1, 3]
summaryRanges.getIntervals(); // return [[1, 1], [3, 3]]
summaryRanges.addNum(7);      // arr = [1, 3, 7]
summaryRanges.getIntervals(); // return [[1, 1], [3, 3], [7, 7]]
summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
summaryRanges.getIntervals(); // return [[1, 3], [7, 7]]
summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
summaryRanges.getIntervals(); // return [[1, 3], [6, 7]]

Constraints:
    0 <= value <= 10^4
    At most 3 * 10^4 calls will be made to addNum and getIntervals.

Follow up: What if there are lots of merges and the number of disjoint intervals is small compared to the size of the data stream?
*/

#include <bits/stdc++.h>
using namespace std;

class SummaryRanges
{
public:
    vector<vector<int>> interval;
    SummaryRanges()
    {
    }

    void addNum(int value)
    {
        int n = interval.size(), inf = INT_MAX;
        vector<int> temp;
        temp.push_back(value);
        int idx = lower_bound(interval.begin(), interval.end(), temp) - interval.begin();

        int pre_start, pre_end, next_start, next_end;
        if (idx <= 0)
        {
            pre_start = -inf;
            pre_end = -inf;
        }
        else
        {
            pre_start = interval[idx - 1][0];
            pre_end = interval[idx - 1][1];
        }

        if (idx >= n)
        {
            next_start = inf;
            next_end = inf;
        }
        else
        {
            next_start = interval[idx][0];
            next_end = interval[idx][1];
        }

        if ((value >= pre_start && value <= pre_end) || (value >= next_start && value <= next_end))
        {
            return;
        }
        else if (pre_end + 1 == value && next_start - 1 == value)
        {
            interval[idx - 1][1] = next_end;
            interval.erase(interval.begin() + idx);
        }
        else if (pre_end + 1 == value)
        {
            interval[idx - 1][1] = value;
        }
        else if (next_start - 1 == value)
        {
            interval[idx][0] = value;
        }
        else
        {
            interval.insert(interval.begin() + idx, {value, value});
        }
    }

    vector<vector<int>> getIntervals()
    {
        return interval;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */