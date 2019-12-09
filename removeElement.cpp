class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int last=0,cur = 0;
        for(; cur < nums.size(); cur++){
            if(nums[cur]!=val) {
                nums[last] = nums[cur];
                last++;
            } 
        }
        return last;
    }
};
