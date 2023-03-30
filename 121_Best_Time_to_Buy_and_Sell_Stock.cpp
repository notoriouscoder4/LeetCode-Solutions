/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

Constraints:
    1 <= prices.length <= 10^5
    0 <= prices[i] <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Given array prices, return max profit w/ 1 buy & 1 sell
    Ex. prices = [7,1,5,3,6,4] -> 5 (buy at $1, sell at $6)

    For each, get diff b/w that & min value before, store max

    Time: O(n)
    Space: O(1)
*/
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mini = prices[0];
        int max_profit = 0;

        for (int i = 1; i < prices.size(); ++i)
        {
            int cost = prices[i] - mini;
            max_profit = max(max_profit, cost);
            mini = min(mini, prices[i]);
        }
        return max_profit;
    }
};

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution obj;

    auto ans = obj.maxProfit(prices);
    cout << "the maximum profit:" << ans << "\n";

    return 0;
}