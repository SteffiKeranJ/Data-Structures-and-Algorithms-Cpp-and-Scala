/**

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3

**/




class Solution {
public:
    int maxProfit(vector<int>& prices) {
	int i, n = prices.size();
    int bestPrice = prices[n-1];
	vector<int>dp(n+1,0);
	for(i = n-2; i >=0; --i) {
		bestPrice = max(prices[i], bestPrice);
		dp[i] = max(dp[i+1], bestPrice - prices[i]);
	}
	bestPrice = prices[0];
	for(i = 1; i < n; ++i) {
		bestPrice = min(prices[i], bestPrice);
		dp[i] = max(dp[i-1], dp[i] + (prices[i] - bestPrice));
	}
	return dp[n-1];
    }
};
