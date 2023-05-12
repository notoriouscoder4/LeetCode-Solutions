/*
You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi, brainpoweri].

The array describes the questions of an exam, where you have to process the questions in order (i.e., starting from question 0)
and make a decision whether to solve or skip each question.

Solving question i will earn you pointsi points but you will be unable to solve each of the next brainpoweri questions.
If you skip question i, you get to make the decision on the next question.

. For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
    . If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
    . If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but you will be unable to solve questions 2 and 3.

Return the maximum points you can earn for the exam.

Example 1:
Input: questions = [[3,2],[4,3],[4,4],[2,5]]
Output: 5
Explanation: The maximum points can be earned by solving questions 0 and 3.
- Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
- Unable to solve questions 1 and 2
- Solve question 3: Earn 2 points
Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.

Example 2:
Input: questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
Output: 7
Explanation: The maximum points can be earned by solving questions 1 and 4.
- Skip question 0
- Solve question 1: Earn 2 points, will be unable to solve the next 2 questions
- Unable to solve questions 2 and 3
- Solve question 4: Earn 5 points
Total points earned: 2 + 5 = 7. There is no other way to earn 7 or more points.

Constraints:
    1 <= questions.length <= 10^5
    questions[i].length == 2
    1 <= pointsi, brainpoweri <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
class Solution_recursion
{
public:
    ll recursive(int idx, vector<vector<int>> &questions)
    {
        if (idx >= questions.size())
            return 0;

        ll take_it = questions[idx][0] + recursive(idx + questions[idx][1] + 1, questions);
        ll leave_it = recursive(idx + 1, questions);

        return max(take_it, leave_it);
    }

    long long mostPoints(vector<vector<int>> &questions)
    {
        return recursive(0, questions);
    }
};

/*
Intuition

    The idea is that each time a recursive function calls itself, it reduces the given problem into subproblems.
    The recursion call continues until it reaches the base cases, where the subproblem can be solved without further recursion.

    We define dfs(i) as the maximum points we can get by processing the problems in the range [i ~ n - 1].
    Similar to approach 1, we have the same recursive formula where dfs(i) is the larger of the points of the two options:

    dfs(i) = max(dfs(i + 1), points[i] + dfs(i + skip[i] + 1))

    Once we move on from dfs(i) to either dfs(i + 1) or dfs(i + skip[i] + 1).
    Then the function calls itself for smaller subproblems.
    When we meet the case that i ≥ n, we have reached the base case where the problem can be solved by just returning 0 without further recursion!

    As we can notice, there may be many repeated calls to dfs.
    To avoid repeated computation over the same case, we can use an array dp as memory.

Algorithm
    1. Initialize an array dp of size n as memory.
    2. Define function dfs(i) as the maximum points in the range [i ~ n - 1].
        2a. If i >= n, return 0, since we can get 0 points from 0 question.
        2b. If dp[i] != 0, it means we have already computed dfs(i), return dp[i].
        2c. Otherwise, we can either solve question i or skip it.
            . By solving it, the point we get is questions[i][0] + dfs(i + questions[i][1] + 1).
            . By skipping it, the point we get is dfs(i + 1).
        2d. Update dp[i] as the larger one.
    3. Call dfs(0) and return its result.
*/
class Solution_memoization
{
public:
    ll memoization(int idx, vector<vector<int>> &questions, vector<ll> &t)
    {
        if (idx >= questions.size())
            return 0;

        if (t[idx] != -1)
            return t[idx];

        ll take_it = questions[idx][0] + memoization(idx + questions[idx][1] + 1, questions, t);
        ll leave_it = memoization(idx + 1, questions, t);

        return t[idx] = max(take_it, leave_it);
    }

    long long mostPoints(vector<vector<int>> &questions)
    {
        vector<ll> t(questions.size(), -1);
        return memoization(0, questions, t);
    }
};

class Solution_tabulation
{
public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();
        vector<ll> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int point = questions[i][0];
            int jump = questions[i][1];

            int nextQuestion = min(n, i + jump + 1);
            dp[i] = max(dp[i + 1], point + dp[nextQuestion]);
        }
        return dp[0];
    }
};

int main()
{
    vector<vector<int>> questions = {{3, 2}, {4, 3}, {4, 4}, {2, 5}};

    Solution_memoization obj;
    auto ans = obj.mostPoints(questions);
    cout << ans << endl;

    return 0;
}