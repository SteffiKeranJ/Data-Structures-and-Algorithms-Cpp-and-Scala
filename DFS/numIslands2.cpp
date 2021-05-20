class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;
        for(int i = 0; i < n; ++i)  {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j]=='1') {
                    ans++;
                    dfs(grid,i, j);
                }
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<char>>& grid, int y, int x) {
        if(x < 0 || x >= grid[0].size() ||
          y < 0 || y >= grid.size() || grid[y][x]!='1') return;
        grid[y][x] = '#';
        dfs(grid, y-1, x);
        dfs(grid, y+1, x);
        dfs(grid, y, x-1);
        dfs(grid, y, x+1);
        
    }
};
