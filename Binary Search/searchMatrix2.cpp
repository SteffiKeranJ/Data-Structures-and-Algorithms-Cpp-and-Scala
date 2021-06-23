class Solution {
public:
    bool binarySearch(int row, int col, int rowsize, vector<vector<int>> matrix, int target) {
	if(row >= rowsize || col < 0) return false;
	if(matrix[row][col] == target) return true;
	if(matrix[row][col] < target) return binarySearch(++row, col, rowsize, matrix, target);	
     return binarySearch(row, --col, rowsize, matrix, target);	
    }


    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int rowsize = matrix.size();
	    return	binarySearch(0, n-1, rowsize, matrix, target);
    }

};
