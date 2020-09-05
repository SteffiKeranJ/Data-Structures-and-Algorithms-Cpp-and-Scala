class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        if(mat.size()==1) return mat[0][0];
        int n = mat[0].size();
        int principal = 0;
        int secondary = 0;
        int i =0;
        for(; i < n; ++i) {
                principal += mat[i][i]; 
                secondary += mat[i][n-i-1];            
        }
        if(n%2!=0) {
            int mid = n/2;
            secondary -= mat[mid][mid];
        }
        return (principal+secondary);
    }

};
