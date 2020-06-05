class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLength = 0;
        int left = 0 ; // incremented for every '('
        int right = 0; // incremented for every ')'
        
        // left to right scan
        for (int i = 0; i < s.length(); ++i) {
            if (s[i]=='(') left++;
            if(s[i]==')') right++;
            if(left == right) maxLength = max(maxLength, 2*left);
            else if(right >= left) {
                left = 0;
                right = 0;
            }
        } 
        left = right = 0;
        for (int i = s.length()-1; i >= 0; i--) {
            if (s[i]=='(') right++;
            if(s[i]==')') left++;
            if(left == right) maxLength = max(maxLength, 2*left);
            else if(right >= left) {
                left = 0;
                right = 0;
            }
        }
        
        return maxLength;
    }
};
