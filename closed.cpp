class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int h = grid.size();
        int w = grid[0].size();
        int count = 0;
        int i,j;
        for(i=0; i < h; ++i) {
            for (j=0; j < w; ++j){
                if(grid[i][j]==0) {
                    count+=dfs(grid, i , j)?1:0;
                }
            }
        }
        return count;
    }

    private:
    bool dfs(vector<vector<int>>&grid, int i, int j) {
        if (i < 0 || j < 0|| i >= grid.size() || j >= grid[0].size()) {
            return false;
        }
        if (grid[i][j]==1) return true;
        grid[i][j] = 1;
        bool d1 = dfs(grid, i+1, j);
        bool d2 = dfs(grid, i-1, j);
        bool d3 = dfs(grid, i, j+1);
        bool d4 = dfs(grid, i, j-1);
        return d1 && d2 && d3 && d4;

    }
};
