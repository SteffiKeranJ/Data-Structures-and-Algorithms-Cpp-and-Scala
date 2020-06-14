class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        //
        int row = matrix.size();
        if (row == 0) return 0;
        int col = matrix[0].size();
        if (col == 0) return 0;
        int res = INT_MIN;
        
        for (int l = 0; l < col; l++) {
            // CREATE AN ARRAY OF THE SAME ROW SIZE OF THE GIVEN MATRIX
            vector<int> tempArr(row, 0);
            // int curMax = INT_MIN;
            // int curSum = 0;
            
            for (int r = l; r < col; r++) { // RIGHT POINTER 
                int curMax = INT_MIN;
                int curSum = 0;
                for (int i = 0; i < row; i++) {
                    tempArr[i] += matrix[i][r]; // SUM OF THAT COLUMN
                    curSum += tempArr[i]; 
                    if (curSum > curMax) {
                        curMax = curSum;
                    }
                    if (curSum < 0) curSum = 0;
                }
                if (curMax <= k) {
                    res = max(res, curMax);
                    continue;
                }
                set<int> s;
                s.insert(0);
                int temp = 0;
                for (int i = 0; i < row; i++) {
                    temp += tempArr[i];
                    auto it = lower_bound(s.begin(),s.end(), temp - k);

                    if (it != s.end()) {
                        res = max(res, temp - *it);
                    }
                    s.insert(temp);
                }
                
            }
            
        }
        return res;
    }
};
