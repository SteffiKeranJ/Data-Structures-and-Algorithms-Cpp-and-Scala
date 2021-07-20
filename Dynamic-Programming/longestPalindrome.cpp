/** 
5. Longest Palindromic Substring
Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),
**/


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool dp[1001][1001] = {false};
        for(int i =0; i <= n; ++i) {
                dp[i][i] = true;
        }
        string res = "";
        res+=s[0];
        for(int i = n-1; i >= 0; --i) {
            for(int j = i+1; j <n; ++j) {
                if(s[i] == s[j]) {
                    if(j-i == 1 || dp[i+1][j-1]) {
                        dp[i][j] = true;
                        if(res.size() < j - i + 1)
                            res = s.substr(i, j-i+1);
                    }
                }
                
            }
        }
        return res;       
    }
};
