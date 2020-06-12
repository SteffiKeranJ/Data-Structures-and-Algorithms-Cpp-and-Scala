class Solution {
        int r;
        int c;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        r = matrix.size();
        if(r == 0) return 0;
        c= matrix[0].size();
        int maxlength = 0;
        vector<vector<int>> dfs(r, vector<int>(c, 0));
        for(int i = 0; i < r; ++i) {
            for(int j = 0 ; j < c; ++j) {
                int curr = recursive(i,j, dfs, matrix);
                maxlength = max(maxlength, curr); 
            }
        }
        return maxlength;
    }
    
    int recursive(int i, int j, vector<vector<int>>& dfs, vector<vector<int>>& matrix) {
        if(dfs[i][j] != 0) return dfs[i][j];
        else {
            int maxi = 1;
            
            // b.c 1
            if (i-1 >= 0 && (matrix[i-1][j]>matrix[i][j])) {
                maxi = max(maxi,1+ recursive(i-1, j, dfs, matrix));
            }
            
            // b.c 2
            if (j -1 >=0 && (matrix[i][j-1]>matrix[i][j])) {
                maxi = max(maxi,1+ recursive(i, j-1, dfs, matrix));
            }
            
            // b.c 3
            
            if (i+1 < r && (matrix[i+1][j]>matrix[i][j])) {
                maxi = max(maxi,1+ recursive(i+1, j, dfs, matrix));
            }
            
            // b.c. 4
            if(j+1 < c && (matrix[i][j+1]>matrix[i][j])) {
                    maxi = max(maxi,1+ recursive(i, j+1, dfs, matrix));
            }            
         dfs[i][j] = maxi;
        return maxi;
        }
       
    }
};
