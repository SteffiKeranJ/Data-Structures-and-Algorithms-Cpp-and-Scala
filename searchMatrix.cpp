class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        int shortDim = min(matrix.size(), matrix[0].size());
        int i;//iterator
        for(i = 0; i < shortDim; i++) {
            bool vertical = binarySearch(matrix, i, target, true);
            bool horizontal = binarySearch(matrix, i , target, false);
            if (vertical || horizontal) return true; 
        }
    return false;
    }
    
    bool binarySearch(vector<vector<int>>& matrix, int start, int target, bool vertical) {
        // low, high, mid
        int low =start;
        int high = vertical ? matrix[0].size()-1 : matrix.size()-1;
        
        while(high >= low) {
            int mid = low + (high - low)/2; // l+r/2;
            if(vertical) {
                if (matrix[start][mid] < target) low = mid+1;
                else if(matrix[start][mid] > target) high = mid-1;
                else return true;
            }
            else {
                 if (matrix[mid][start] > target) high = mid-1;
                else if(matrix[mid][start] < target) low = mid+1;
                else return true;
            }
        }
        return false;
    }
    
};
