/*
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

Example 1:
Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2
Since 2 has only one digit, return it.

Example 2:
Input: num = 0
Output: 0

Constraints:
    0 <= num <= 23^1 - 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int addDigits(int num)
    {
        int digitalRoot = 0;
        while (num > 0)
        {
            digitalRoot += num % 10;
            num /= 10;

            if (num == 0 && digitalRoot > 9)
            {
                num = digitalRoot;
                digitalRoot = 0;
            }
        }
        return digitalRoot;
    }
};

/*
The digital root or digital sum of a non-negative integer is the single-digit value obtained by an iterative process of summing digits,
on each iteration using the result from the previous iteration to compute the digit sum.
The process continues until a single-digit number is reached.

The digital root of a number is equal to the remainder when that number is divided by 9.
If the remainder is 0 and the number is greater than 0, then the digital root is 9. If the number is 0,
then the digital root of the number is 0.

For example, the digital root of the number 12,345 is 6 because 1 + 2 + 3 + 4 + 5 equals 15 and then 1 + 5 equals 6.

A shortcut to finding digital root:

Example:-
    Casting out 9’s:

    Consider the number 27518. Its digital root is 5 because 2 + 7 + 5 + 1 + 8 = 23 and 2 + 3 = 5.

    Now, the digital sum of 27518 can also be calculated by simply grouping (2 + 7) + 5 + (1 + 8), 
    where the un-grouped value 5 is the digital root (since 2 + 7 = 9 and 1 + 8 = 9 are eliminated from the calculation).


Properties of digital root:

    .If we multiply any number by 9, the digital root will always be 9.
    .Adding 9 to a number does not change the digital root of that number.
    .If we divide any number by 9, the digital root of that number will be the remainder.
*/

class Solution_Digital_Root_Algo
{
public:
    int addDigits(int num)
    {
        return num == 0 ? 0 : 1 + (num - 1) % 9;
    }
};