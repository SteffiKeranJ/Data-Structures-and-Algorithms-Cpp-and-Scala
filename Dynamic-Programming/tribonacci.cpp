class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if (n == 1 || n==2 ) return 1;
        int dp[n+1] = {0};
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        int i = 3;
        for(i = 3; i <=n; i++) {
            dp[i]= dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
};
