class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> res;
        for(int i = 0; i < A.size(); i++) {
            vector<int>temp;
            for(int j = A[i].size()-1; j >= 0; j--) {
                bitset<1>bit(A[i][j]);
                temp.push_back((int)bit.flip().to_ulong());
            }
            res.push_back(temp);
        }
        return res;
    }
};
