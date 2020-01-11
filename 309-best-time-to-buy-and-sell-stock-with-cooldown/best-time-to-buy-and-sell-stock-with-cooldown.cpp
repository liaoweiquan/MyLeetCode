// Say you have an array for which the ith element is the price of a given stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
//
//
// 	You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
// 	After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
//
//
// Example:
//
//
// Input: [1,2,3,0,2]
// Output: 3 
// Explanation: transactions = [buy, sell, cooldown, buy, sell]
//


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp[100007][3];
        memset(dp, -0x3f3f3f, sizeof(dp));
        int n = prices.size();
        dp[0][1] = dp[0][2] = 0;
        for (int i = 0; i < n; ++ i) {
            dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + prices[i]);
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][0]);
            dp[i + 1][2] = max(dp[i + 1][2], dp[i][1]);
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][2] - prices[i]);
            dp[i + 1][2] = max(dp[i + 1][2], dp[i][2]);
        }
        int ans = max(dp[n][0], dp[n][1]);
        ans = max(ans, dp[n][2]);
        return ans;
    }
};
