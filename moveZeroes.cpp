class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int last = 0, cur = 0; cur < nums.size(); cur++){
            if(nums[cur]!=0){
                int b = nums[cur];
                nums[cur] = nums[last];
                nums[last++] = b;
            }
        }
    }
};
