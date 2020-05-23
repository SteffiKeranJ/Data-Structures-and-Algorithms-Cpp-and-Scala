class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for(int i = 0; i < matrix.size()-1; ++i) {
            for(int j = i; j < matrix[0].size(); ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
