class Solution
{
    public:
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        int dp[1001][1001] = {0};
        int i, j;
       for(i = 1; i <= n; ++i) {
           for(j = 1; j <=W; ++j) {
               if(j<wt[i-1]) {
                   dp[i][j] = dp[i-1][j];
               } else {
                   dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j - wt[i-1]]);
               }
           }
       }
       return dp[n][W];
    }
};
