/*

*/

#include <bits/stdc++.h>
using namespace std;

class Solution_Tabulation
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> length(nums.size(), 1);
        for (int k = 0; k < nums.size(); k++)
        {
            for (int i = 0; i < k; i++)
            {
                if (nums[i] < nums[k])
                    length[k] = max(length[k], length[i] + 1);
            }
        }
        return *max_element(length.begin(), length.end());
    }
};

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    Solution_Tabulation obj;
    auto ans = obj.lengthOfLIS(nums);
    cout << ans << "\n";

    return 0;
}