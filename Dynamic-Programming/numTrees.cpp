class Solution {
public:
    int numTrees(int n) {
        int dp[20] ={0};
        dp[0] = dp[1] = 1;
        int i, j;
        for(i = 2; i <=n ;++i) {
            for(j =1; j <= i; ++j) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};
