int Solution::maxSubArray(const vector<int> &A) {
    int n = A.size();
    if(n==0) return 0;
    if(n == 1) return A[0];
    int S[n+1]={0};
    S[0] = A[0];
    int i, maxSum = A[0];
    for(i = 1; i < n; ++i) {
        S[i] = max(S[i-1]+A[i], A[i]);
        maxSum = max(S[i], maxSum);
    }
    return maxSum;
}

int max(int a, int b) {
    return a > b? a:b;
}
