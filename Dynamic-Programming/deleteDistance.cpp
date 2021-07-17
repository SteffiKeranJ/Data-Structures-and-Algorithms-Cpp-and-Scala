/** 
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4

**/


class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int dp[501][501] = {0};
        int i, j;
        for(i = 1; i <=m; ++i )
            dp[0][i] = i;
        for(i = 1; i <=n; ++i) 
            dp[i][0] = i;
        
        for(i = 1; i <=n; ++i) {
            for(j = 1; j <=m; ++j) {
                if(word1[j-1] == word2[i-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][m];
    }
};
