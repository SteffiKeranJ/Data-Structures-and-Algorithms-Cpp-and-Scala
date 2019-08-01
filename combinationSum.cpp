class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int>local;
        sort(candidates.begin(), candidates.end());
        findTarget(candidates, target, local, res, 0);
        return res;
    }
    
    void findTarget(vector<int>& candidates, int target, vector<int>&local, vector<vector<int>>& res, int begin) {
        if(target == 0) {
            res.push_back(local);
            return;
        } else {
            for(int i = begin; i < candidates.size(); i++) {
                if(candidates[i]> target) return;
                local.push_back(candidates[i]);
                findTarget(candidates, target-candidates[i], local, res, i);
                local.pop_back();
            }
        }
    }
};
