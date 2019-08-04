class Solution {
public:
    string reverseVowels(string s) {
    string res = "";
    stack<char>st;
        for(int i = 0; i < s.length(); i++){
        if (s[i] == 'a' ||s[i] == 'e' ||s[i] == 'i' ||s[i] == 'o'||s[i] == 'u' || s[i] == 'A' ||s[i] == 'E' ||s[i] == 'I' ||s[i] == 'O'||s[i] == 'U'){
            st.push(s[i]);
            }
        }
        for(int i = 0; i < s.length(); i++) {
            if (s.at(i) == 'a' ||s[i] == 'e'||s[i] == 'i'||s[i] == 'o' ||s[i] == 'u' || s[i] == 'A' ||s[i] == 'E' ||s[i] == 'I' ||s[i] == 'O'||s[i] == 'U'){
                res+=st.top();
                st.pop();
            } else {
                res+=s[i];
            }
        }
        return res;
    }
};
