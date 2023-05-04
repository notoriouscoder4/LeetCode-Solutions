/*
In the world of Dota2, there are two parties: the Radiant and the Dire.

The Dota2 senate consists of senators coming from two parties. Now the Senate wants to decide on a change in the Dota2 game.
The voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:

    1. Ban one senator's right: A senator can make another senator lose all his rights in this and all the following rounds.

    2. Announce the victory: If this senator found the senators who still have rights to vote are all from the same party,
    he can announce the victory and decide on the change in the game.

Given a string senate representing each senator's party belonging.
The character 'R' and 'D' represent the Radiant party and the Dire party.
Then if there are n senators, the size of the given string will be n.

The round-based procedure starts from the first senator to the last senator in the given order.
This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.

Suppose every senator is smart enough and will play the best strategy for his own party.
Predict which party will finally announce the victory and change the Dota2 game. The output should be "Radiant" or "Dire".

Example 1:
Input: senate = "RD"
Output: "Radiant"
Explanation:
The first senator comes from Radiant and he can just ban the next senator's right in round 1.
And the second senator can't exercise any rights anymore since his right has been banned.
And in round 2, the first senator can just announce the victory since he is the only guy in the senate who can vote.

Example 2:
Input: senate = "RDD"
Output: "Dire"
Explanation:
The first senator comes from Radiant and he can just ban the next senator's right in round 1.
And the second senator can't exercise any rights anymore since his right has been banned.
And the third senator comes from Dire and he can ban the first senator's right in round 1.
And in round 2, the third senator can just announce the victory since he is the only guy in the senate who can vote.

Constraints:
    n == senate.length
    1 <= n <= 10^4
    senate[i] is either 'R' or 'D'.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Time complexity:o(n)
    Space complexity:o(n)
*/
class Solution_two_queues
{
public:
    string predictPartyVictory(string senate)
    {
        // Number of Senator
        int n = senate.size();

        // Queues with Senator's Index.
        // Index will be used to find the next turn of Senator
        queue<int> rQueue;
        queue<int> dQueue;

        // Populate the Queues
        for (int i = 0; i < n; i++)
        {
            if (senate[i] == 'R')
            {
                rQueue.push(i);
            }
            else
            {
                dQueue.push(i);
            }
        }

        // While both parties have at least one Senator
        while (!rQueue.empty() && !dQueue.empty())
        {

            // Pop the Next-Turn Senate from both Q.
            int rTurn = rQueue.front();
            rQueue.pop();
            int dTurn = dQueue.front();
            dQueue.pop();

            // ONE having a larger index will be banned by a lower index
            // Lower index will again get Turn, so EN-Queue again
            // But ensure its turn comes in the next round only
            if (dTurn < rTurn)
            {
                dQueue.push(dTurn + n);
            }
            else
            {
                rQueue.push(rTurn + n);
            }
        }

        // One's which Empty is not winner
        return rQueue.empty() ? "Dire" : "Radiant";
    }
};

/*
    Time complexity:o(n)
    Space complexity:o(n)
*/
class Solution_one_queue
{
public:
    string predictPartyVictory(string senate)
    {

        // Number of Senators of each party
        int rCount = 0, dCount = 0;

        // Floating Ban Count
        int dFloatingBan = 0, rFloatingBan = 0;

        // Queue of Senators
        queue<char> q;
        for (char c : senate)
        {
            q.push(c);
            if (c == 'R')
                rCount++;
            else
                dCount++;
        }

        // While any party has eligible Senators
        while (rCount && dCount)
        {

            // Pop the senator with turn
            char curr = q.front();
            q.pop();

            // If eligible, float the ban on the other party, enqueue again.
            // If not, decrement the floating ban and count of the party.
            if (curr == 'D')
            {
                if (dFloatingBan)
                {
                    dFloatingBan--;
                    dCount--;
                }
                else
                {
                    rFloatingBan++;
                    q.push('D');
                }
            }
            else
            {
                if (rFloatingBan)
                {
                    rFloatingBan--;
                    rCount--;
                }
                else
                {
                    dFloatingBan++;
                    q.push('R');
                }
            }
        }

        // Return the party with eligible Senators
        return rCount ? "Radiant" : "Dire";
    }
};