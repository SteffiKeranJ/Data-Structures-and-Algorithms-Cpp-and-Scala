/** 
516. Longest Palindromic Subsequence
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.

**/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int dp[1001][1001] = {0};
        int n = s.size();
        for(int i = 1; i <= n;  ++i) {
            for(int j = n-1; j >= 0; --j) {
                if(s[i-1] == s[j]) 
                    dp[i][j] = 1 + dp[i-1][j+1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j+1]);
            }
        }
        return dp[n][0];
    }
};
