/** 
647. Palindromic Substrings
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
**/

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        if(n == 1) return 1;
        bool dp[1001][1001] = {false};
        for(int i=0; i <n;++i ) {
            dp[i][i] = true;
            count++;
        }
        for(int i = n-1; i >=0; --i) {
            for(int j = i+1; j <n;++j) {
                if(s[i] == s[j]) {
                    if(j-i==1 || dp[i+1][j-1] == true) {
                        dp[i][j] = true;
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
