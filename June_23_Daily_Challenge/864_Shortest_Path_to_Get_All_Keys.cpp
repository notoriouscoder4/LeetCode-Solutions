/*
You are given an m x n grid grid where:

'.' is an empty cell.
'#' is a wall.
'@' is the starting point.
Lowercase letters represent keys.
Uppercase letters represent locks.

You start at the starting point and one move consists of walking one space in one of the four cardinal directions.
You cannot walk outside the grid, or walk into a wall.

If you walk over a key, you can pick it up and you cannot walk over a lock unless you have its corresponding key.

For some 1 <= k <= 6, there is exactly one lowercase and one uppercase letter of the first k letters of the English alphabet in the grid.
This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.

Return the lowest number of moves to acquire all keys. If it is impossible, return -1.

Example 1:
Input: grid = ["@.a..","###.#","b.A.B"]
Output: 8
Explanation: Note that the goal is to obtain all the keys not to open all the locks.

Example 2:
Input: grid = ["@..aA","..B#.","....b"]
Output: 6

Example 3:
Input: grid = ["@Aa"]
Output: -1

Constraints:
    m == grid.length
    n == grid[i].length
    1 <= m, n <= 30
    grid[i][j] is either an English letter, '.', '#', or '@'.
    The number of keys in the grid is in the range [1, 6].
    Each key in the grid is unique.
    Each key in the grid has a matching lock.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPathAllKeys(vector<string> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        queue<vector<int>> q;
        vector<vector<int>> moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        // seen['key'] is only for BFS with key state equals 'keys'
        unordered_map<int, unordered_set<pair<int, int>>> seen;

        unordered_set<char> keySet, lockSet;
        int allKeys = 0;
        int startRow = -1, startCol = -1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char cell = grid[i][j];
                if (cell >= 'a' && cell <= 'f')
                {
                    allKeys += (1 << (cell - 'a'));
                    keySet.insert(cell);
                }
                if (cell >= 'A' && cell <= 'F')
                {
                    lockSet.insert(cell);
                }
                if (cell == '@')
                {
                    startRow = i;
                    startCol = j;
                }
            }
        }

        // [row, column, key state, distance]
        q.push({startRow, startCol, 0, 0});
        seen[0].insert(make_pair(startRow, startCol));

        while (!q.empty())
        {
            vector<int> cur = q.front();
            q.pop();
            int curR = cur[0], curC = cur[1], keys = cur[2], dist = cur[3];
            for (vector<int> &move : moves)
            {
                int newR = curR + move[0], newC = curC + move[1];

                // If this cell (newR, newC) is reachable.
                if (newR >= 0 && newR < m && newC >= 0 && newC < n && grid[newR][newC] != '#')
                {
                    char cell = grid[newR][newC];

                    // If it is a key:
                    if (keySet.count(cell))
                    {
                        // If we have collected it before, no need to revisit this cell.
                        if (((1 << (cell - 'a')) & keys) != 0)
                        {
                            continue;
                        }

                        // Otherwise, we can walk to this cell and pick it up.
                        int newKeys = (keys | (1 << (cell - 'a')));

                        // If we collect all keys, return dist + 1.
                        // Otherwise, just add this state to seen and queue.
                        if (newKeys == allKeys)
                        {
                            return dist + 1;
                        }
                        seen[newKeys].insert(make_pair(newR, newC));
                        q.push({newR, newC, newKeys, dist + 1});
                    }

                    // If it is a lock and we don't have its key, continue.
                    if (lockSet.count(cell) && ((keys & (1 << (cell - 'A'))) == 0))
                    {
                        continue;
                    }

                    // We can walk to this cell if we haven't been here before with the same key state.
                    else if (seen[keys].count(make_pair(newR, newC)) == 0)
                    {
                        seen[keys].insert(make_pair(newR, newC));
                        q.push({newR, newC, keys, dist + 1});
                    }
                }
            }
        }
        return -1;
    }
};