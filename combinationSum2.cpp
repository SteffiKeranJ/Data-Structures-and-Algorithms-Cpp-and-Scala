class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int>local;
        sort(candidates.begin(), candidates.end());
        findTarget(candidates, target, 0, local, res);
        return res;
    }
    
    void findTarget(vector<int>& candidates, int target, int order, vector<int>&local, vector<vector<int>>& res) {
        if(target == 0) {
            res.push_back(local);
            return;
        } else {
            for(int i = order; i < candidates.size(); i++) {
                if(candidates[i]> target) return;
                if (i && candidates[i] == candidates[i-1] && i > order) continue;
                local.push_back(candidates[i]);
                findTarget(candidates, target-candidates[i], i+1, local, res);
                local.pop_back();
            }
        }
    }
};
