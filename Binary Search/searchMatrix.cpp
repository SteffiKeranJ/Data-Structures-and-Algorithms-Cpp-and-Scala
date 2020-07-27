class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(!m) return false;
        int n = matrix[0].size();
        
        int left = 0;
        int right = (m * n)-1;
        int pivotIdx, pivotElement;
        while(left <= right){
            pivotIdx = left + (right - left)/2;
            pivotElement = matrix[pivotIdx / n][pivotIdx % n];
            if(target == pivotElement) return true;
            else {
                if (target < pivotElement) right = pivotIdx - 1;
                else left = pivotIdx + 1;
            }
        }
        return false;
    }
};
