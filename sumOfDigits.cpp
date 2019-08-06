class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        sort(A.begin(), A.end());
        int sum = 0;
        while(A[0] > 0) {
            sum+=A[0]%10;
            A[0]/=10;
        }
        return !(sum%2);
    }
};
