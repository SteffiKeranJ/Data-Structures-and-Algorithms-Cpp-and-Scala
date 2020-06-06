class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size(); // number of rows
        int n = obstacleGrid[0].size(); // number of columns
        
        if(obstacleGrid[0][0] == 1|| obstacleGrid[m-1][n-1] == 1) return 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                
                if(obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = -1; // we need to deviate the obstacle
                    continue;
                }
                
                if(i ==0 && j == 0) {
                    obstacleGrid[i][j] = 1;
                    continue;
                }
                
                if(i == 0) { // for any cell in the top row, which can be reached from the left
                    obstacleGrid[i][j] = obstacleGrid[i][j-1] == -1 ? obstacleGrid[i][j] : obstacleGrid[i][j-1];
                    continue; // go back to the loop
                }
                
                if(j==0) { // for any cell in the leftmost column which can be reached only from the cell above it
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] == -1 ? obstacleGrid[i][j] : obstacleGrid[i-1][j];
                    continue; // go back to the loop
                }
                
                // for any other cell which can be reached either from the above or from the left 
                // given, no obstacle is there
                int top = 0;
                int left = 0;
                top = obstacleGrid[i-1][j] == -1 ? 0 : obstacleGrid[i-1][j];
                left = obstacleGrid[i][j-1] == -1 ? 0 : obstacleGrid[i][j-1];
                
                obstacleGrid[i][j] = top + left; // as the cell can be either from one of the ways: from above or from the left
            }
        }
        return obstacleGrid[m-1][n-1] == -1 ? 0 : obstacleGrid[m-1][n-1];
    }
};
