/*
A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.

Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.

Example 1:
Input: arr = [3,5,1]
Output: true
Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.

Example 2:
Input: arr = [1,2,4]
Output: false
Explanation: There is no way to reorder the elements to obtain an arithmetic progression.

Constraints:
    2 <= arr.length <= 1000
    -10^6 <= arr[i] <= 10^6
*/

#include <bits/stdc++.h>
using namespace std;

/*
    TC: O(NlogN)
    SC: O(N) or O(logN)
*/
class Solution_sorting
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];

        for (int i = 2; i < arr.size(); ++i)
        {
            if (arr[i] - arr[i - 1] != diff)
            {
                return false;
            }
        }

        return true;
    }
};

/*
Intuition
    Actually, we don't need to sort arr.
    Instead, we can take advantage of a feature of the arithmetic sequence: the difference between any two adjacent terms is equal.

    Let's assume we have an arithmetic sequence where the first term is min_value and every successive element has a common difference diff.
    Then, the difference between each number arr[i] and min_value must be divisible by diff.
    We can determine diff by finding the minimum and maximum values, taking their difference, and dividing by the number of elements between the minimum and maximum which is n - 1.

    diff = (max_value - min_value) / (n - 1).

    Next, we traverse arr and check if each element arr[i] belongs to this arithmetic sequence. If the difference between arr[i] and min_value is a multiple of diff, then arr[i] belongs to this sequence, otherwise, it does not.

    This strategy might not work if there are duplicate elements.
    For example, let arr = [1, 2, 3, 2, 5]. diff would be (5 - 1) / 4 = 1.
    The algorithm will be "tricked" since each element will pass the test (arr[i] - 1 divisible by 1).

    To counteract this, we will use a set number_set to store all the elements we encounter.
    After traversing the array, if the size of the set is equal to n, then the numbers are distinct and must form an arithmetic sequence from min_value to max_value.

    Note that we need to consider some special cases:
        . If max_value - min_value is not divisible by n - 1, it means arr can't form an arithmetic sequence, return false.
        . If we have diff = 0, it means that all the numbers in arr are equal, and we can return true directly.

Algorithm
    1. Find the minimum value min_value and the maximum value max_value of arr, let n be the length of arr.

    2. Check if max_value - min_value is divisible by n - 1, return false if not. Otherwise, set diff = (max_value - min_value) / (n - 1).

    3. Initialize an empty set number_set.

    4. Iterate over arr, for each number arr[i]:

        . Check if arr[i] - min_value is divisible by diff, return false if not.
        . Add arr[i] to number_set.

    5. Return true if the size of number_set equals n, return false otherwise.


Complexity Analysis
    TC: O(N)
    SC: O(N)
*/
class Solution_set
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        int minValue = *min_element(arr.begin(), arr.end());
        int maxValue = *max_element(arr.begin(), arr.end());
        int n = arr.size();

        if (maxValue - minValue == 0)
            return true;

        if ((maxValue - minValue) % (n - 1) != 0)
            return false;

        int diff = (maxValue - minValue) / (n - 1);
        unordered_set<int> numberSet;

        for (int i = 0; i < n; i++)
        {
            if ((arr[i] - minValue) % diff != 0)
                return false;
            numberSet.insert(arr[i]);
        }
        return numberSet.size() == n;
    }
};

class Solution_In_place_Modification
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        int minValue = *min_element(arr.begin(), arr.end());
        int maxValue = *max_element(arr.begin(), arr.end());
        int n = arr.size();

        if ((maxValue - minValue) % (n - 1) != 0)
        {
            return false;
        }

        int diff = (maxValue - minValue) / (n - 1);
        int i = 0;

        while (i < n)
        {
            // If arr[i] is at the correct index, move on.
            if (arr[i] == minValue + i * diff)
            {
                i += 1;

                // If arr[i] doesn't belong to this arithmetic sequence, return false.
            }
            else if ((arr[i] - minValue) % diff != 0)
            {
                return false;

                // Otherwise, find the index j to which arr[i] belongs, swap arr[j] with arr[i].
            }
            else
            {
                int j = (arr[i] - minValue) / diff;

                // If we find duplicated elements, return False.
                if (arr[i] == arr[j])
                {
                    return false;
                }

                // Swap arr[i] with arr[j].
                swap(arr[i], arr[j]);
            }
        }

        return true;
    }
};
