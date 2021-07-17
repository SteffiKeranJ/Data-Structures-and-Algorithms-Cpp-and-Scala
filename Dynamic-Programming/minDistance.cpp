/** 
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
**/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(); // source
        int n = word2.size(); // destination
        
        if(m == 0 && n == 0) return 0;
        int dp[501][501] = {0};
        
        int i, j; // iterators
        for(i = 1; i <=m; ++i) {
            dp[0][i] = i;
        } 
        for(i = 1; i <=n;++i) {
            dp[i][0] = i;
        }
        for(i = 1; i <=n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(word1[j-1] == word2[i-1]) 
                    dp[i][j] = dp[i-1][j-1];
                else {
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
                }
            }
        }
        return dp[n][m];
    }
};
