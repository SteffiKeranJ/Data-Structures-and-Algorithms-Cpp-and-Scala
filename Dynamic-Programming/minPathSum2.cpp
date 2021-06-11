class Solution {
public:
    int dp[201][201]={0};
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i, j;
        for(i = 0; i <= m; ++i) {
            dp[i][0] = 0;
        }
        for(i = 0; i <=n;++i) {
            dp[0][i] = 0;
        }
        for(i = 1; i <=m; ++i) {
            for(j = 1; j <=n; ++j) {
                if(i==1) {
                    dp[i][j] = dp[i][j-1]+grid[i-1][j-1];
                } else if(j ==1) {
                    dp[i][j] = dp[i-1][j] + grid[i-1][j-1];
                } else {
                    dp[i][j] = grid[i-1][j-1] + min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
