class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int maxStart = 0;
        int maxEnd = 0;
        int curSum = 0;
        int curStart = 0;
        for(int curEnd = 0; curEnd < nums.size(); ++curEnd) {
            curSum += nums[curEnd];
            if(curSum > maxSum) {
                maxSum = curSum;
                maxStart = curStart;
                maxEnd = curEnd;
            }
            
            if (curSum < 0) {
                curSum =0;
                curStart = curEnd + 1;
            }
        }
        return maxSum;
    }
};
