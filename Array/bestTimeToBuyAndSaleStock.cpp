#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the maximum profit
int maxProfit(vector<int> &prices)
{
    // -------------------- INTUITION --------------------
    //
    // We want to buy at the LOWEST price seen so far
    // and sell at the CURRENT price.
    //
    // At every day:
    // Profit = Current Price - Minimum Price Seen Till Now
    //
    // Keep updating:
    // 1. Minimum buying price
    // 2. Maximum profit

    int mini = prices[0]; // Minimum price seen so far
    int profit = 0;       // Maximum profit

    for (int i = 1; i < prices.size(); i++)
    {
        // Profit if we sell today
        int cost = prices[i] - mini;

        // Update maximum profit
        profit = max(profit, cost);

        // Update minimum buying price
        mini = min(mini, prices[i]);
    }

    return profit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Only function call
    cout << "Maximum Profit: " << maxProfit(prices);

    return 0;
}

/*
=========================
STRIVER'S INTUITION
=========================

Goal:
Buy once and Sell once to maximize profit.

Key Observation:
For every day,
pretend you SELL on that day.

Then the best BUY price is simply the
minimum price seen before that day.

Algorithm:

mini = prices[0]

For each day:
    profit = currentPrice - mini
    update maximum profit
    update mini

Example:

prices = [7, 1, 5, 3, 6, 4]

Day 1:
mini = 7

Day 2:
mini = 1

Day 3:
profit = 5 - 1 = 4

Day 4:
profit = 3 - 1 = 2

Day 5:
profit = 6 - 1 = 5  <-- Maximum

Answer = 5

Time Complexity : O(n)
Space Complexity: O(1)

Memory Trick:

Keep track of:
1. Lowest buying price so far.
2. Best profit if selling today.

Formula:
profit = currentPrice - minimumPriceSeen
*/