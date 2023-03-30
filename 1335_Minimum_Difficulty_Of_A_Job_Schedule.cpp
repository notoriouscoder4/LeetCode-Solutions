/*
You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the ith job, you have to finish all the jobs j where 0 <= j < i).
You have to finish at least one task every day.
The difficulty of a job schedule is the sum of difficulties of each day of the d days.
The difficulty of a day is the maximum difficulty of a job done on that day.
You are given an integer array jobDifficulty and an integer d. The difficulty of the ith job is jobDifficulty[i].
Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.

Example 1:
Input: jobDifficulty = [6,5,4,3,2,1], d = 2
Output: 7
Explanation: First day you can finish the first 5 jobs, total difficulty = 6.
Second day you can finish the last job, total difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7

Example 2:
Input: jobDifficulty = [9,9,9], d = 4
Output: -1
Explanation: If you finish a job per day you will still have a free day. you cannot find a schedule for the given jobs.

Example 3:
Input: jobDifficulty = [1,1,1], d = 3
Output: 3
Explanation: The schedule is one job per day. total difficulty will be 3.

Constraints:
1 <= jobDifficulty.length <= 300
0 <= jobDifficulty[i] <= 1000
1 <= d <= 10
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
      int recursionSol(vector<int> &jobd, int n, int i, int d)
      {
            if (d == 1)
                  return *max_element(begin(jobd) + i, end(jobd));
            int result = INT_MAX;
            int currD = INT_MIN;
            for (int j = i; j <= n - d; ++j)
            {
                  currD = max(currD, jobd[j]);
                  result = min(result, currD + recursionSol(jobd, n, j + 1, d - 1));
            }
            return result;
      }

      int memoizeSol(vector<int> &jobd, int n, int i, int d, int dp[301][11])
      {
            if (d == 1)
                  return *max_element(begin(jobd) + i, end(jobd));
            if (dp[i][d] != -1)
                  return dp[i][d];
            int result = INT_MAX;
            int currD = INT_MIN;
            for (int j = i; j <= n - d; ++j)
            {
                  currD = max(currD, jobd[j]);
                  result = min(result, currD + recursionSol(jobd, n, j + 1, d - 1));
            }
            dp[i][d] = result;
            return dp[i][d];
      }

public:
      int minDifficulty(vector<int> &jobDifficulty, int d)
      {
            /* Recursive Sol code
            int n = jobDifficulty.size();
            if (n < d)
                  return -1;
            return recursionSol(jobDifficulty, n, 0, d);
            */
            int dp[301][11];
            memset(dp, -1, sizeof(dp));
            int n = jobDifficulty.size();
            if (n < d)
                  return -1;
            return memoizeSol(jobDifficulty, n, 0, d, dp);
      }
};