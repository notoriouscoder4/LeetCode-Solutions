/*
You are the manager of a basketball team.
For the upcoming tournament, you want to choose the team with the highest overall score.
The score of the team is the sum of scores of all the players in the team.

However, the basketball team is not allowed to have conflicts.
A conflict exists if a younger player has a strictly higher score than an older player.
A conflict does not occur between players of the same age.

Given two lists, scores and ages, where each scores[i] and ages[i] represents the score and age of the ith player, respectively,
return the highest overall score of all possible basketball teams.

Example 1:
Input: scores = [1,3,5,10,15], ages = [1,2,3,4,5]
Output: 34
Explanation: You can choose all the players.

Example 2:
Input: scores = [4,5,6,5], ages = [2,1,2,1]
Output: 16
Explanation: It is best to choose the last 3 players. Notice that you are allowed to choose multiple people of the same age.

Example 3:
Input: scores = [1,2,3,5], ages = [8,9,10,1]
Output: 6
Explanation: It is best to choose the first 3 players.

Constraints:
    1 <= scores.length, ages.length <= 1000
    scores.length == ages.length
    1 <= scores[i] <= 10^6
    1 <= ages[i] <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[1001][1001];

    int findMaxScore(vector<pair<int, int>> &ageScorePair, int prev, int index)
    {
        // Return 0 if we have iterated over all the players.
        if (index >= ageScorePair.size())
            return 0;

        // We have already calculated the answer, so no need to go into recursion.
        if (dp[prev + 1][index] != -1)
            return dp[prev + 1][index];

        // If we can add this player, return the maximum of two choices we have.
        if (prev == -1 || ageScorePair[index].second >= ageScorePair[prev].second)
            return dp[prev + 1][index] = max(findMaxScore(ageScorePair, prev, index + 1), ageScorePair[index].second + findMaxScore(ageScorePair, index, index + 1));

        // This player cannot be added; return the corresponding score.
        return dp[prev + 1][index] = findMaxScore(ageScorePair, prev, index + 1);
    }

    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        vector<pair<int, int>> ageScorePair;
        for (int i = 0; i < scores.size(); i++)
        {
            ageScorePair.push_back({ages[i], scores[i]});
        }

        // Sort in ascending order of age and then by score.
        sort(ageScorePair.begin(), ageScorePair.end());
        memset(dp, -1, sizeof(dp));
        return findMaxScore(ageScorePair, -1, 0);
    }

    int bestTeamScore_updated_version(vector<int> &scores, vector<int> &ages)
    {
        int n = scores.size();
        int dp[n], ans = 0;
        vector<pair<int, int>> players;
        for (int i = 0; i < n; i++)
            players.push_back({ages[i], scores[i]});
        sort(players.begin(), players.end());
        for (int i = 0; i < n; i++)
        {
            dp[i] = players[i].second;
            for (int j = 0; j < i; j++)
            {
                if (players[j].second <= players[i].second)
                    dp[i] = max(dp[i], dp[j] + players[i].second);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};