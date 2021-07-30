class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0); 
        int n = nums.size();
        
        int leftSum = 0;
        
        for(int i = 0; i < n; ++i) {
            if(leftSum == sum - leftSum - nums[i]) return i;
            leftSum += nums[i];
        }
        return -1;
    }   
};
