class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string SS= s+s;
        int n = SS.size();
        SS = SS.substr(1, n-2);
        return SS.find(s) == string::npos ? false :  true;
    }
};
