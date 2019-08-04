class Solution {
public:
    string toLowerCase(string str) {
        string res = "";
        for(int i = 0; i < str.size(); i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                res+=str[i] | 32;
            } else {
                res+=str[i];
            }
        }
        return res;
    }
};
