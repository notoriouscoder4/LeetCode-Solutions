/*
You are given an array nums of n positive integers.

You can perform two types of operations on any element of the array any number of times:

1.  If the element is even, divide it by 2.
    For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
2.  If the element is odd, multiply it by 2.
    For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].

The deviation of the array is the maximum difference between any two elements in the array.

Return the minimum deviation the array can have after performing some number of operations.

Example 1:
Input: nums = [1,2,3,4]
Output: 1
Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], then the deviation will be 3 - 2 = 1.

Example 2:
Input: nums = [4,1,5,20,3]
Output: 3
Explanation: You can transform the array after two operations to [4,2,5,5,3], then the deviation will be 5 - 2 = 3.

Example 3:
Input: nums = [2,10,8]
Output: 3

Constraints:
    n == nums.length
    2 <= n <= 5 * 10^4
    1 <= nums[i] <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

/*
Intuition
    The problem asks to perform two types of operations on any element of the array any number of times, 
    which involves dividing an even number by 2 and multiplying an odd number by 2. 
    Our goal is to minimize the deviation of the array, which is the maximum difference between any two elements in the array.

    The intuition behind the approach is to convert odd numbers to even numbers by multiplying them by 2 and then inserting them into a max heap. 
    We can then perform division operations on the maximum element in the heap until we get an odd number, and then insert it back into the heap. 
    We continue this process until we can't divide the maximum element in the heap.

    At each step, we update the minimum element in the heap and check if the difference between the maximum and minimum elements in the heap is less than the current answer. 
    If it is, we update the answer. Finally, we return the minimum deviation.

    The reason for using a max heap is that we want to get the maximum number in the heap quickly, 
    which is the number that will give us the maximum deviation when paired with the minimum number in the heap.

Approach
    1. Store each odd number in the vector and multiply by 2 to make it even and then insert it into the max heap, which will store even numbers.
    2. Pop the maximum element from the heap and perform a division operation until we get an odd number.
    3. Check if the difference between the maximum and minimum elements in the heap is less than the current answer. If it is, update the answer.
    4. Insert the odd number obtained in step 2 in the heap and update the minimum element if it is less than the current minimum.
    5. Continue the process until we can't divide the maximum element in the heap.

Complexity
    Time complexity:O(nlogn)
    Space complexity:O(n)
*/
class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        priority_queue<int> maxHeap; // max heap to store even numbers
        int minEle = INT_MAX;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                maxHeap.push(nums[i]);
                minEle = min(minEle, nums[i]);
            }
            else
            {
                maxHeap.push(nums[i] * 2);
                minEle = min(minEle, nums[i] * 2);
            }
        }

        int minDeviation = INT_MAX;
        while (!maxHeap.empty())
        {
            int maxx = maxHeap.top();
            maxHeap.pop();

            minDeviation = min(minDeviation, maxx - minEle);
            if (maxx % 2 != 0)
                break;
            minEle = min(minEle, maxx / 2);
            maxHeap.push(maxx / 2);
        }
        return minDeviation;
    }
};

int main()
{
    vector<int> nums = {4, 1, 5, 20, 3};

    Solution obj;
    auto ans = obj.minimumDeviation(nums);
    cout << "Minimum Deviation = " << ans << "\n";

    return 0;
}