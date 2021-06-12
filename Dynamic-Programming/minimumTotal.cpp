class Solution {
public:
    int dp[201][201]={0};
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int i, j;
        for(i =0; i < n; ++i) {
            dp[n-1][i] = triangle[n-1][i];
        }
        
        for(i = n-2; i >= 0; --i) {
            for(j = i; j >=0; --j) {
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
            }
        }
        return dp[0][0];        
    }
};
