/*
A program was supposed to print an array of integers.
The program forgot to print whitespaces and the array is printed as a string of digits s and all we know is that all integers in the array were in the range [1, k] and there are no leading zeros in the array.

Given the string s and the integer k, return the number of the possible arrays that can be printed as s using the mentioned program.
Since the answer may be very large, return it modulo 10^9 + 7.

Example 1:
Input: s = "1000", k = 10000
Output: 1
Explanation: The only possible array is [1000]

Example 2:
Input: s = "1000", k = 10
Output: 0
Explanation: There cannot be an array that was printed this way and has all integer >= 1 and <= 10.

Example 3:
Input: s = "1317", k = 2000
Output: 8
Explanation: Possible arrays are [1317],[131,7],[13,17],[1,317],[13,1,7],[1,31,7],[1,3,17],[1,3,1,7]

Constraints:
    1 <= s.length <= 10^5
    s consists of only digits and does not contain leading zeros.
    1 <= k <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(const string &s, long k, int i, vector<int> &t)
    {
        if (i == s.size())
            return 1;
        if (s[i] == '0')
            return 0;
        if (t[i] != -1)
            return t[i];

        int ans = 0;
        long num = 0;
        for (int j = i; j < s.size(); j++)
        {
            num = num * 10 + s[j] - '0';
            if (num > k)
                break;
            ans = (ans + dfs(s, k, j + 1, t)) % 1000000007;
        }
        return t[i] = ans;
    }

    int numberOfArrays(string s, int k)
    {
        vector<int> t(s.size(), -1);
        return dfs(s, k, 0, t);
    }
};

int main()
{
    string s = "1317";
    int k = 2000;

    Solution obj;
    auto ans = obj.numberOfArrays(s, k);
    cout << ans << "\n";

    return 0;
}