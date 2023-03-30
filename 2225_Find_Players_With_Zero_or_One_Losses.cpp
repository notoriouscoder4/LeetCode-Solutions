/*
You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.

Return a list answer of size 2 where:

answer[0] is a list of all players that have not lost any matches.
answer[1] is a list of all players that have lost exactly one match.
The values in the two lists should be returned in increasing order.

Note:

You should only consider the players that have played at least one match.
The testcases will be generated such that no two matches will have the same outcome.

Example 1:
Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
Output: [[1,2,10],[4,5,7,8]]
Explanation:
Players 1, 2, and 10 have not lost any matches.
Players 4, 5, 7, and 8 each have lost one match.
Players 3, 6, and 9 each have lost two matches.
Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].

Example 2:
Input: matches = [[2,3],[1,3],[5,4],[6,4]]
Output: [[1,2,5,6],[]]
Explanation:
Players 1, 2, 5, and 6 have not lost any matches.
Players 3 and 4 each have lost two matches.
Thus, answer[0] = [1,2,5,6] and answer[1] = [].

Constraints:
    1 <= matches.length <= 10^5
    matches[i].length == 2
    1 <= winneri, loseri <= 10^5
    winner[i] != loser[i]
    All matches[i] are unique.
*/

#include <bits/stdc++.h>
using namespace std;

/*
In the previous approaches, we store players without so we need to sort them after adding them to arrays.
Can we store the players in order so that we don't need an additional sorting process after we collect them?

Notice that the valid range of players is of the same order of magnitude as the size of match.
This reminds us of counting sort, a sorting algorithm with linear time complexity.

What is Counting Sort?

In short, Counting Sort is not a comparison sort; thus, the O(n⋅log⁡(n)) time complexity for comparison sorting does not apply.
Note that the approach we use to solve this problem is not exactly a counting sort,
but has the same idea behind it: mapping each of the players to an (unique) index within a specific range.

We create an auxiliary array (losses_count) and fill it with a specific value (let's say -1)
indicating that none of the players have played the match yet.
For each match [winner, loser], we modify losses_count[winner] and losses_count[loser] to other numbers than -1 to reflect that both players have played at least one match.

How do we use different values to represent different kinds of players?

    losses_count[i] = -1, player i has not played.
    losses_count[i] = 0, player i has played at least one game and has 0 loss.
    losses_count[i] = 1, player i has exact 1 loss.
    losses_count[i] > 1, player i has more than 1 loss.
Therefore, we initialize all the values in losses_count as -1, iterate through matches and update values at index winner and loser for each match.
Each value losses_count[i] != -1 stands for a player i who has played at least one match.
We just need to iterate over losses_count from low to high and add the two kinds of players to corresponding arrays, so we don't need to sort them anymore.

Algorithm:
    Use an array losses_count to store the number of losses for each player. Initially, losses_count[i] = -1 for every index i.
    For each match [winner, loser]:
    If losses_count[loser] = -1, set it to 1, otherwise increment it by 1.
    If losses_count[winner] = -1, set it to 0.
    Iterate over losses_count and use two arrays to store these 2 kinds of players, for each index i:
    If losses_count[i] = 0, add this player to the first array.
    If losses_count[i] = 1, add this player to the second array.
*/
class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        vector<int> lossesCount(100001, -1);

        for (auto &match : matches)
        {
            int winner = match[0], loser = match[1];
            if (lossesCount[winner] == -1)
                lossesCount[winner] = 0;
            if (lossesCount[loser] == -1)
                lossesCount[loser] == 1;
            else
                lossesCount[loser]++;
        }

        vector<vector<int>> answer(2, vector<int>());
        for (int i = 1; i < 100001; ++i)
        {
            if (lossesCount[i] == 0)
                answer[0].push_back(i);
            else if (lossesCount[i] == 1)
                answer[1].push_back(i);
        }

        return answer;
    }
};
