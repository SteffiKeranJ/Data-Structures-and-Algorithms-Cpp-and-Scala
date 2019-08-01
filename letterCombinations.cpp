class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>letter({"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
        vector<string> res;
        if(digits.length() == 0) return res;
        backtrackHelper("", digits, 0,  res, letter);
        return res;
    }
    
    void backtrackHelper(string combination, string& digits, int pos, vector<string>& res, vector<string>& letter) {
       if(pos == digits.size()){
            res.push_back(combination);
            return;
        }
        for(auto x: letter[digits[pos]-'0']){
             combination.push_back(x);
            backtrackHelper(combination, digits, pos+1, res, letter);
            combination.pop_back();
        }
    }
};
