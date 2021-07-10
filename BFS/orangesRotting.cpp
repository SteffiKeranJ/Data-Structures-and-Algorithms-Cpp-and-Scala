/** 
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
**/



class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
	int m = grid[0].size();
	queue<pair<int, int>> Q;
	int counter = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(grid[i][j] == 2) {
				Q.push({i, j});
			}
		}
	}	
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
	while(!Q.empty()) {
        int qsize = Q.size();
        for(int s = 0; s < qsize;++s) {
            pair<int, int> cell = Q.front();
            Q.pop();
            int i = cell.first;
            int j = cell.second;
           
            for(int d = 0; d < dir.size(); ++d) {
                int row = i + dir[d].first;
                int col = j + dir[d].second;
                
                if(col < m && row < n && col >= 0 && row >= 0 && grid[row][col] == 1){
                    Q.push({row, col});
                    grid[row][col] = 2;
                }
            }
        }
       
        if(!Q.empty()) counter++;
	}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(grid[i][j]==1) return -1;
		}
	}
    
	return counter;
    }
};
