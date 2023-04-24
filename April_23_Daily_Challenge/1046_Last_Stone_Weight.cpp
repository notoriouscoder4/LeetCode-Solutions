/*
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together.
Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.

Example 1:
Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation:
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.

Example 2:
Input: stones = [1]
Output: 1

Constraints:
    1 <= stones.length <= 30
    1 <= stones[i] <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

/*
Intuition
    sort in descending order and going through the first two elements and repeating the process.

Approach
    The approach is very simple. Follow the following steps to understand the approach.

    1)Sort the stones vector in descending order.
    2)store the difference of first two numbers(stones[0] and stones[1]) in res.
    3)If res is 0 then remove stones[0] and stones[1]. If res is not equal to zero which is a positve integer, then remove the front element in the vector and replace the res value with front element in the vector. (Since we need to remove 1st two elements and push the positve integer, instead of that am removing one element and replacing the other).
    4)Repeat the steps until stones vector is having atleast 2 elements.
    5)If there is an element in the stones vector, then that is our answer else return 0.

Complexity
    Time complexity: O(N*LogN)
    Space complexity: O(1)
*/
class Solution_sorting
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        sort(stones.begin(), stones.end(), greater<int>());
        int i = 0;
        while (i < stones.size() && (i + 1) < stones.size())
        {
            int res = stones[i] - stones[i + 1];
            if (res != 0)
            {
                stones.erase(stones.begin());
                stones[0] = res;
                sort(stones.begin(), stones.end(), greater<int>());
            }
            else
            {
                stones.erase(stones.begin(), stones.end() + 2);
            }
        }
        if (stones.size())
            return stones[0];
        return 0;
    }
};

/*
Intuition
    Just read the question nicely, It says every time you have to pick the stones with largest weight,
    so for sure you might have sorted the Array and applied a greedy approach,
    but you'll have to perform sort operation everytime you perform a operation.

    So priority queue uses a Data structure called Max heap for the implemenation where the top node is always the maximum
    and we can get it in 0(1) time.

    You can see the code we just pop two top stones with highest weight and put a stone again in it.

Approach
    Simple thinking, Heap Data structure greedy.

Complexity
    Time complexity: Creation of priority-O(nlogn)
*/
class Solution_maxHeap
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        int n = stones.size();
        priority_queue<int> maxHeap;
        for (int i = 0; i < n; i++)
            maxHeap.push(stones[i]);
        while (maxHeap.size() >= 2)
        {
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();
            if (x != y)
                maxHeap.push(abs(y - x));
        }
        if (maxHeap.size() == 0)
            return 0;
        return maxHeap.top();
    }
};