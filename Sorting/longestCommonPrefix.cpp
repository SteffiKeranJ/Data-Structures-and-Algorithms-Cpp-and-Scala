class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        // sort the strings in alphabetical order
        sort(strs.begin(), strs.end());
        int n = strs.size();
        // the strings common in the first and last string will be common among all strings
        int firstLength = strs[0].size();
        for(int i = 0; i < firstLength; ++i) {
            if(strs[0][i] == strs[n-1][i]) res+=strs[0][i];
            else break;
        }
        return res;
        
    }
};
