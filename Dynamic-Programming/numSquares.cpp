class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        dp[0] = 0;
        for(int i = 1; i <= n; ++i) {
            dp[i] = dp[i-1]+1;
            for(int j = 2; j*j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j*j]+1 );
            }
        }
        return dp[n];
    }
};
