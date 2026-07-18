class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp[i][0] = max profit at day i if we are in 'sell' state (holding stock)
        // dp[i][1] = max profit at day i if we are in 'buy' state (not holding stock)
        // We need n+1 rows to handle the base case where i = n (after last day)
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Base case: On day n (past the last day), profit is 0.
        // The vector is already initialized to 0, so no explicit loop needed here.

        // Iterate backwards from the last day to the first day
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;

                if (buy) {
                    // Option 1: Buy today (-price) and move to sell state (0) next day
                    // Option 2: Don't buy, stay in buy state (1) next day
                    profit = max(-prices[ind] + dp[ind + 1][0], 
                                 dp[ind + 1][1]);
                } else {
                    // Option 1: Sell today (+price) and move to buy state (1) next day
                    // Option 2: Don't sell, stay in sell state (0) next day
                    profit = max(prices[ind] + dp[ind + 1][1], 
                                 dp[ind + 1][0]);
                }

                dp[ind][buy] = profit;
            }
        }

        // The answer is the max profit starting at day 0 in the 'buy' state (1)
        return dp[0][1];
    }
};