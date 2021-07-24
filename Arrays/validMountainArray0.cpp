class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size()==0) return false;
        int i;
        bool res = false;
        if ( A.size() > 2) {
            for (i = 1; i <= A.size()-2; i++) {
                if (res) {
                    if (A[i] > A[i+1]) continue;
                    else {
                        res = false;
                        break;
                    }
                } else if (A[i-1] > A[i]) {
                    res = false;
                    break;
                }
                else {
                    if (A[i] > A[i+1] && A[i] > A[i-1]) {
                        res = true;
                    }
                }
            }
        }
        return res;
    }
};
