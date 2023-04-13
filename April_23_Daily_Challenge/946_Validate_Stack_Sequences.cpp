/*

*/

#include <bits/stdc++.h>
using namespace std;

/*
    TC: O(N),
    SC: O(N)
*/
class Solution_using_stack
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> st;
        int j = 0;
        for (int x : pushed)
        {
            st.push(x);
            while (st.size() > 0 && st.top() == popped[j])
            {
                st.pop();
                j++;
            }
        }
        return st.size() == 0;
    }
};

/*
    TC: O(N),
    SC: O(1)
*/
class Solution_using_2_pointers
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        int i = 0, j = 0;
        for (int x : pushed)
        {
            pushed[i++] = x;
            while (i > 0 && pushed[i - 1] == popped[j])
                --i, ++j;
        }
        return i == 0;
    }
};