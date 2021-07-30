class Solution {
public:
    // 4 decisions : left, right, up or down
    // matrix[i][j] = matrix[i-1][j], matrix[i][j-1], matrix[i+1][j], matrix[i][j+1]
    int dp[201][201] = {0};
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;
    int DFS(vector<vector<int>>& matrix, int i , int j) {
        if(dp[i][j]!=0) return dp[i][j];
        for(int d = 0; d < dir.size(); ++d) {
            int r = dir[d][0] + i;
            int c = dir[d][1] + j;
            if(r >= 0 && r < m && c >= 0 && c < n && (matrix[i][j] < matrix[r][c])) {
                dp[i][j] = max(dp[i][j], DFS(matrix, r, c));
            }
        }
        return ++dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int ans = 0;
        
        for(int i = 0; i < m; ++i) {
            for(int j =0; j < n;++j) {
                ans = max(ans, DFS(matrix, i, j));
            }
        }
        return ans;
        
    }
};
