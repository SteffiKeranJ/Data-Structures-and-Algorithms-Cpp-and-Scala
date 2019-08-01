class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, "", n, 0);
        return res;
    }
    void helper(vector<string>& res, string s, int leftparen, int rightparen) {
        if(!leftparen && !rightparen) {
            res.push_back(s);
            return;
        }
        if (leftparen > 0)
            helper(res, s+"(", leftparen-1, rightparen+1);
        if(rightparen >0)
            helper(res, s+")", leftparen, rightparen-1);
    }
};
