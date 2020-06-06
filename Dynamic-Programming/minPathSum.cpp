class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); // number of rows
        int n =  grid[0].size(); // number of columns
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j) {
                if(i == 0&& j==0) continue;
                if(i==0) { // for first row cells
                    grid[i][j] += grid[i][j-1]; // add from the cell left to it
                    continue; // go back to the loop
                }
                if(j ==0) { //for the first column cells
                    grid[i][j] += grid[i-1][j]; // add from the cells above it
                    continue;
                }
                // for any other cell
                // sum by adding from the cell above it
                int topSum = grid[i][j] + grid[i-1][j];
                // sum by adding from the cell left to it
                int leftSum = grid[i][j] + grid[i][j-1];
                // choose the minimum sum path
                grid[i][j] = min(topSum, leftSum);
            }
        }
        
        return grid[m-1][n-1];
    }
};
