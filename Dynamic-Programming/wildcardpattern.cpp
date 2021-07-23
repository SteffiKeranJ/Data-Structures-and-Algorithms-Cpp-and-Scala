/** 10. Regular Expression Matching

Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input: s = "aab", p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
Example 5:

Input: s = "mississippi", p = "mis*is*p*."
Output: false

**/


class Solution {
public:
    bool dp[21][31] = {false};
    bool isMatch(string s, string p) {
        int sLength = s.size();
        int pLength = p.size();
        dp[0][0] = true;
        
        for(int j = 1; j<=pLength;++j) {
            if(p[j-1]=='*') {
                dp[0][j] = dp[0][j-2];
            }
        }
        
        for(int i = 1; i <=sLength; ++i) {
            for(int j = 1; j <=pLength; ++j) {
                bool match = s[i-1] == p[j-1] || (p[j-1] == '.');
                if(p[j-1] == '*') {
                    dp[i][j] = dp[i][j-2];
                    if(p[j-2]=='.' || s[i-1] == p[j-2])
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                } else if(match) dp[i][j]=dp[i-1][j-1];
                else dp[i][j] = false;
            }
        }
        return dp[sLength][pLength];
        
    }
};
