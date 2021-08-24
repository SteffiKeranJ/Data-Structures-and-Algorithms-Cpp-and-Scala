class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(!mat.size()) return mat;
        int n = mat.size();
        int m = mat[0].size();
        if(n*m != (r*c)) return mat;
        
        vector<vector<int>> res(r, vector<int>(c));
        queue<int> q;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                q.push(mat[i][j]);
            }
        }
        
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                int front = q.front();
                res[i][j] = front;
                q.pop();
            }
        }
        return res;        
    }
};
