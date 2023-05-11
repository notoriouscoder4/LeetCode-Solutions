/*
You are given two integer arrays nums1 and nums2.
We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.

We may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:

    1. nums1[i] == nums2[j], and
    2. the line we draw does not intersect any other connecting (non-horizontal) line.

Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).

Return the maximum number of connecting lines we can draw in this way.

Example 1:
Input: nums1 = [1,4,2], nums2 = [1,2,4]
Output: 2
Explanation: We can draw 2 uncrossed lines as in the diagram.
We cannot draw 3 uncrossed lines, because the line from nums1[1] = 4 to nums2[2] = 4 will intersect the line from nums1[2]=2 to nums2[1]=2.

Example 2:
Input: nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
Output: 3

Example 3:
Input: nums1 = [1,3,7,1,7,5], nums2 = [1,9,2,5,1]
Output: 2

Constraints:
    1 <= nums1.length, nums2.length <= 500
    1 <= nums1[i], nums2[j] <= 2000
*/

#include <bits/stdc++.h>
using namespace std;

class Solution_Recursive
{
public:
    int recursive(int i, int j, vector<int> &nums1, vector<int> &nums2)
    {
        if (i == nums1.size() || j == nums2.size())
            return 0;

        int cnt = 0;
        if (nums1[i] == nums2[j])
            cnt = 1 + recursive(i + 1, j + 1, nums1, nums2);
        else
            cnt += max(recursive(i + 1, j, nums1, nums2), recursive(i, j + 1, nums1, nums2));

        return cnt;
    }

    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        return recursive(0, 0, nums1, nums2);
    }
};

class Solution_Memoization
{
public:
    int t[2001][2001];
    int memoization(int i, int j, vector<int> &nums1, vector<int> &nums2)
    {
        if (i == nums1.size() || j == nums2.size())
            return 0;
        if (t[i][j] != -1)
            return t[i][j];

        int cnt = 0;
        if (nums1[i] == nums2[j])
            cnt = 1 + memoization(i + 1, j + 1, nums1, nums2);
        else
            cnt += max(memoization(i + 1, j, nums1, nums2), memoization(i, j + 1, nums1, nums2));

        return t[i][j] = cnt;
    }

    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        memset(t, -1, sizeof(t));
        return memoization(0, 0, nums1, nums2);
    }
};

class Solution_Tabulation
{
public:
    int t[2001][2001];
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        memset(t, 0, sizeof(t));
        int n = nums1.size(), m = nums2.size();

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];
                else
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }

        return t[n][m];
    }
};

int main()
{
    vector<int> nums1 = {2, 5, 1, 2, 5};
    vector<int> nums2 = {10, 5, 2, 1, 5, 2};

    Solution_Recursive obj;
    auto ans = obj.maxUncrossedLines(nums1, nums2);
    cout << ans << endl;

    return 0;
}