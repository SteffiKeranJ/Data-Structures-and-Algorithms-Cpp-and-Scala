/** 
91. Decode Ways

A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The answer is guaranteed to fit in a 32-bit integer.

 

Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
Example 3:

Input: s = "0"
Output: 0
Explanation: There is no character that is mapped to a number starting with 0.
The only valid mappings with 0 are 'J' -> "10" and 'T' -> "20", neither of which start with 0.
Hence, there are no valid ways to decode this since all digits need to be mapped.
Example 4:

Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").

**/

class Solution {
public:
    unordered_map<int, int> dp;
    int recursiveMemo(int pos, string s) {
        if(s[pos] == '0') return 0; // if the first char is 0, terminate by returning zero
        int n = s.size();
        if(pos == n || pos == n-1) return 1; // terminating case of the recursion
        
        if(dp.find(pos)!= dp.end()) return dp[pos];
        
        int ans = recursiveMemo(pos+1, s); // decode next character
        // check for 2 characters
        if(stoi(s.substr(pos, 2)) <=26) { // decode 2 characters
            ans+= recursiveMemo(pos+2, s);
        }
        dp[pos] = ans;
        return ans;
        
    }
        
    int numDecodings(string s) {
        return recursiveMemo(0,s);
    }
};
