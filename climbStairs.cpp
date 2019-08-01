class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+2, -1);
        return climbingDp(n, dp);
    }
    
    int climbingDp(int n, vector<int>& dp) {
        if (n < 0) return 0; 
        if (n == 0 ) return 1;
        if (dp[n] > -1) return dp[n];
        dp [n] = climbingDp(n-1, dp) + climbingDp(n-2, dp);
        return dp[n];
    }
};
