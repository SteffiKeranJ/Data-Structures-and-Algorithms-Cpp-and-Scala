class Solution {
  public:
    int dp[101][101];
    
    int findED(string s, string t, int m, int n) {
        if(m == -1) return n+1;
        if(n == -1) return m+1;
        
        if(dp[m][n]!=-1) return dp[m][n];
        
        if(s[m]==t[n]) return dp[m][n] = findED(s,t, m-1, n-1);
        int costReplace  = findED(s, t, m-1, n-1);
        int costInsertY = findED(s, t, m-1, n);
        int costDeleteX = findED(s, t, m , n-1);
        
        dp[m][n] = 1 + min(costReplace, min(costInsertY, costDeleteX));
        return dp[m][n];
    }
    
    int editDistance(string s, string t) {
        memset(dp, -1, sizeof(dp));
        int m = s.size();
        int n = t.size();
        return findED(s, t, m -1, n-1);
        
    }
};
