class Solution {
public:
    int grid[101][101]={0};
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(m == 0 || n == 0) return 0;
        if(m == 1 && n==1) return !obstacleGrid[m-1][n-1];
        int i, j;
        for(i = 0; i <=m;++i) {
            grid[i][0]=0;
        }
        for(i = 0; i <=n;++i) {
            grid[0][i] = 0;
        }
        for(i = 1; i <=m;++i) {
            for(j = 1; j <= n;++j) {
                if(i == 1 && j ==1) grid[i][j]= !obstacleGrid[i-1][j-1];
                else{
                    grid[i][j] = obstacleGrid[i-1][j-1]!=1? grid[i-1][j] + grid[i][j-1] : 0;
                }
            }
        }
        return grid[m][n];
    }
};
