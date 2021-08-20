class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int currentSum = nums[0];
        int maxSum = nums[0];
        for(int i = 1; i < n; ++i) {
            currentSum = max(currentSum + nums[i], nums[i]);
            maxSum = max(maxSum, currentSum);          
        }
        return maxSum;
    }
};
