class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int edge=0, n=0, w=0, e=0, s=0;
        int len= grid.size(), wid=grid[0].size();
        
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]){
                    n = (i>0)? grid[i-1][j]: 0;
                    w = (j>0)? grid[i][j-1]: 0;
                    e = (j<wid-1)?grid[i][j+1]:0;
                    s = (i<len-1)? grid[i+1][j]:0;
                
                    edge += 4*grid[i][j] - (n+w+e+s);
                }
            }
        }
        return edge;
    }
};

