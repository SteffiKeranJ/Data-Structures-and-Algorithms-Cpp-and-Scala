class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i;
        int min = INT_MAX;
        int max = INT_MAX;
        if (nums.empty()) return false;
        for (i = 0; i < nums.size(); i++) {
            if(nums[i] < min) {
                min = nums[i];
            }
            else if(nums[i] < max && nums[i] > min) {
                max = nums[i];
            }  else if(nums[i] > max) return true;
        }
       return false;
    }
};
