/*
Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21

Constraints:
    -2^31 <= x <= 2^31 - 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        long r = 0; // declare r
        while (x)
        {
            r = r * 10 + x % 10; // find remainder and add its to r
            x = x / 10;          // Update the value of x
        }
        if (r > INT_MAX || r < INT_MIN)
            return 0; // check 32 bit range
        return int(r);
    }
};