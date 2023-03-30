/*

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximizeWin_sliding_window(vector<int> &prizePositions, int k)
    {
        int n = prizePositions.size();
        if (k == 0)
            return min(n, 2);

        vector<int> left(n + 1, 0), right(n + 1, 0);
        left[0] = 1;
        for (int i = 1, j = 0; i < n; i++)
        {
            while (prizePositions[i] - prizePositions[j] > k)
                j++;
            left[i] = max(left[i - 1], i - j + 1);
        }

        right[n - 1] = 1;
        for (int i = n - 1, j = n - 1; i >= 0; i--)
        {
            while (prizePositions[j] - prizePositions[i] > k)
                j--;
            right[i] = max(right[i + 1], j - i + 1);
        }

        int res = 0;
        for (int i = 0; i <= n; i++)
        {
            res = max(res, (i == 0 ? 0 : left[i - 1]) + (i == n ? 0 : right[i]));
        }
        return res;
    }
    
    int maximizeWin(vector<int> &prizePositions, int k)
    {
        int res = 0, n = prizePositions.size(), j = 0;
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            while (prizePositions[j] < prizePositions[i] - k)
                ++j;
            dp[i + 1] = max(dp[i], i - j + 1);
            res = max(res, i - j + 1 + dp[j]);
        }
        return res;
    }
};