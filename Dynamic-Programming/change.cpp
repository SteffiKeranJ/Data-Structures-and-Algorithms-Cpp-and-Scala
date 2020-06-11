class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount+1);        // bottom-up approach
        dp[0] = 1;  // because only way if no change
        for(int i = 0; i < n; ++i) {
            for(int j = 1; j <amount+1; ++j) {
                if (coins[i] <= j) {
                    dp[j] += dp[j - coins[i]];
                }
            }
        }
        return dp[amount];
    }
};
