class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backTrack(nums, res, 0);
        return res;
    }
    
    void backTrack(vector<int>& nums, vector<vector<int>>& res, int order) {
        if(order>= nums.size()){
            res.push_back(nums);
            return;
        }
        else{
            for(int i = order; i < nums.size(); i++){
                swap(nums[order], nums[i]);
                backTrack(nums, res, order+1);
                swap(nums[order], nums[i]);
            }
        }
    }
};
