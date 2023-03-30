#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums)
{
      int n = nums.size();
      n = n * (n + 1) / 2;

      int ans{0};
      for (int num : nums)
            ans += num;
      return n - ans;
}

int main()
{
      vector<int> nums{3, 0, 1};
      int ans = missingNumber(nums);
      cout << ans << "\n";
      return 0;
}