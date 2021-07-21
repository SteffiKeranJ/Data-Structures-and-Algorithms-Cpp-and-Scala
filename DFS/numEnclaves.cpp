class Solution {
public:
    int m, n;
    void DFS(vector<vector<int>> &grid, int row, int col) {
        if(row < 0 || col < 0 || row > m-1 || col > n-1 ) return; 
        if(grid[row][col] != 1) return;
        grid[row][col] = -1;
        DFS(grid, row+1, col);
        DFS(grid, row-1, col);
        DFS(grid, row, col+1);
        DFS(grid, row, col-1);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == 0 || j == 0 || i == m-1 || j==n-1) {
                    DFS(grid, i , j);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) ans++;
            }
        }
        return ans;       
    }
};
