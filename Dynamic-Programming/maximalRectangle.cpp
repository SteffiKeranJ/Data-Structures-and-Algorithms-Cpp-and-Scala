class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // empty case
        int n =matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        int maxarea = 0;
        // create a vector int dp matrix
        vector<vector<int>> dp (n, vector<int>(m, 0));
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(matrix[i][j] == '1') {
                    dp[i][j] = j == 0 ? 1 : dp[i][j-1] + 1;
                    int width  = dp[i][j];
                    for(int k = i; k >=0; --k) {
                        width = min(width, dp[k][j]);
                        maxarea = max(maxarea, width * (i - k + 1));
                    }
                }
            }
        }
        return maxarea;
    }
};
