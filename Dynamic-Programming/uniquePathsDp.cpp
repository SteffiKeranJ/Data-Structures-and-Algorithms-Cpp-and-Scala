class Solution {
    int grid[101][101]={0};
public:
    int uniquePaths(int m, int n) {
        int i;
        for(i = 0 ; i<=m; ++i){
            grid[i][0]=0; // 0 ways
        }
        for(i = 0 ; i<=n; ++i){
            grid[0][i]=0; // 0 ways
        }
        for(i = 1; i <= m; ++i) {
            for(int j = 1; j<= n; ++j) {
                if(i == 1 && j ==1) grid[i][j] = 1; // 1 way
                else
                    grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
        }
        return grid[m][n];
    }
};
