/** 
Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

Example 1:

Input:
S = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole
string(not individual words), the input
string becomes
much.very.program.this.like.i

**/
class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        stack<string> charStack;
        string res;
        string temp;
        for(int i = 0; i < S.size(); ++i) {
            if(S[i]=='.') {
                charStack.push(temp);
                temp = "";
            }
            else temp+=S[i];
        }
        if(temp!="") charStack.push(temp);
        while(!charStack.empty()) {
            res+=charStack.top();
            charStack.pop();
            if(!charStack.empty()) res+='.';
        }
        return res;
    } 
};
