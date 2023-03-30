/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Example 1:
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

Constraints:
    -2^31 <= val <= 2^31 - 1
    Methods pop, top and getMin operations will always be called on non-empty stacks.
    At most 3 * 10^4 calls will be made to push, pop, top, and getMin.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Design stack that supports push, pop, top, & retriving min element

    2 stacks, 1 normal & 1 monotonic decr, only push if lower than top

    Time: O(1)
    Space: O(n)
*/
class MinStack
{
private:
    stack<int> stk;
    stack<int> minStk;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        stk.push(val);

        if (minStk.empty())
            minStk.push(val);
        else if (val <= minStk.top())
            minStk.push(val);
    }

    void pop()
    {
        if (stk.empty())
            return;
        if (stk.top() == minStk.top())
            minStk.pop();
        stk.pop();
    }

    int top()
    {
        if (stk.empty())
            return -1;
        return stk.top();
    }

    int getMin()
    {
        if (minStk.empty())
            return -1;
        return minStk.top();
    }
};

int main()
{
    MinStack obj;
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    cout << obj.getMin() << "\n";
    obj.pop();
    cout << obj.top() << "\n";
    cout << obj.getMin() << "\n";
}