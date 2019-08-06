class Solution {
public:
    int fixedPoint(vector<int>& A) {
        for(int i = 0; i < A.size(); i++) {
            if(A[i] == i){
                return i;
                break;
            } 
        }
        return -1;
    }
};
