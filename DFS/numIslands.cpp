class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int height = grid.size();
        int width = grid[0].size();
        vector<vector<bool>> visited(height, vector<bool>(width, false));
        
        int count = 0;
        for(int y = 0 ; y < height ; ++y) {
            for(int x = 0 ; x < width; ++x) {
                if (grid[y][x] == '1' && !visited[y][x]) {
                    // landed on a new island!!
                    count++;
                    conquer(grid, visited, x, y);
                }
            }
        }
        return count;
    }
    
    void conquer(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        if (y < 0 || x < 0 || y == grid.size() || x == grid[0].size() || grid[y][x] == '0' || visited[y][x]) { // undesired conditions
            return;
        }
        visited[y][x] = true;
        conquer(grid, visited, x+1, y);
        conquer(grid, visited, x-1, y);
        conquer(grid, visited, x, y+1);
        conquer(grid, visited, x, y-1);
    }
};
