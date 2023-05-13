/*
Given the integers zero, one, low, and high, we can construct a string by starting with an empty string,
and then at each step perform either of the following:

1. Append the character '0' zero times.
2. Append the character '1' one times.

This can be performed any number of times.

A good string is a string constructed by the above process having a length between low and high (inclusive).

Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.

Example 1:
Input: low = 3, high = 3, zero = 1, one = 1
Output: 8
Explanation:
One possible valid good string is "011".
It can be constructed as follows: "" -> "0" -> "01" -> "011".
All binary strings from "000" to "111" are good strings in this example.

Example 2:
Input: low = 2, high = 3, zero = 1, one = 2
Output: 5
Explanation: The good strings are "00", "11", "000", "110", and "011".

Constraints:
    1 <= low <= high <= 10^5
    1 <= zero, one <= low
*/

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
class Solution_recursive
{
public:
    int lenGoodString(int len, int zero, int one)
    {
        if (len == 0)
            return 1;
        if (len < 0)
            return 0;

        long long sum = (lenGoodString(len - one, zero, one) + lenGoodString(len - zero, zero, one)) % mod;
        return sum;
    }

    int countGoodStrings(int low, int high, int zero, int one)
    {
        int ans = 0;
        for (int len = low; len <= high; len++)
            ans = (ans + lenGoodString(len, zero, one)) % mod;
        return ans;
    }
};

/*
    TC: O(high)
    SC: O(high)
*/
class Solution_memoization
{
public:
    int lenGoodString(int len, int zero, int one, vector<int> &t)
    {
        if (len == 0)
            return 1;
        if (len < 0)
            return 0;

        if (t[len] != -1)
            return t[len];

        long long sum = (lenGoodString(len - one, zero, one, t) + lenGoodString(len - zero, zero, one, t)) % mod;
        return t[len] = sum;
    }

    int countGoodStrings(int low, int high, int zero, int one)
    {
        vector<int> t(high + 1, -1);
        int ans = 0;
        for (int len = low; len <= high; len++)
            ans = (ans + lenGoodString(len, zero, one, t)) % mod;
        return ans;
    }
};
