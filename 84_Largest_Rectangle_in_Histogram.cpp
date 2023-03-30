/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1,
return the area of the largest rectangle in the histogram.

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:
Input: heights = [2,4]
Output: 4

Constraints:
    1 <= heights.length <= 10^5
    0 <= heights[i] <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> NSLIndex(vector<int> &heights)
    {
        vector<int> nslIndex(heights.size());
        stack<int> nslStack;

        for (int i = 0; i < heights.size(); ++i)
        {
            while (!nslStack.empty() && heights[nslStack.top()] >= heights[i])
                nslStack.pop();
            if (nslStack.empty())
                nslIndex[i] = -1;
            else
                nslIndex[i] = nslStack.top();
            nslStack.push(i);
        }
        return nslIndex;
    }

public:
    vector<int> NSRIndex(vector<int> &heights)
    {
        vector<int> nsrIndex(heights.size());
        stack<int> nsrStack;

        for (int i = heights.size() - 1; i >= 0; --i)
        {
            while (!nsrStack.empty() && heights[nsrStack.top()] >= heights[i])
                nsrStack.pop();
            if (nsrStack.empty())
                nsrIndex[i] = heights.size();
            else
                nsrIndex[i] = nsrStack.top();
            nsrStack.push(i);
        }
        return nsrIndex;
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> nslIndex = NSLIndex(heights);
        vector<int> nsrIndex = NSRIndex(heights);

        int largest_rectangle_area = INT_MIN;
        for (int i = 0; i < heights.size(); ++i)
        {
            int width = nsrIndex[i] - nslIndex[i] - 1;
            int height = heights[i];

            int area = width * height;
            largest_rectangle_area = max(largest_rectangle_area, area);
        }
        return largest_rectangle_area;
    }
};

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    Solution obj;
    auto ans = obj.largestRectangleArea(heights);
    cout << "The largest rectangle in the histogram: " << ans << "\n";

    return 0;
}