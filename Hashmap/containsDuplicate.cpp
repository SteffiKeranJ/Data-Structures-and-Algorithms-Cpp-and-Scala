class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numSet;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(numSet.find(nums[i])!=numSet.end()) return true;
            numSet.insert(nums[i]);
        }
        return false;
    }
};
