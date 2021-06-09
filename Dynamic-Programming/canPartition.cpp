class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); ++i) {
            count+=nums[i];
        }
        if (count%2!=0) return false;
        int halfSum = count/2;
        int n = nums.size();
        
        bool dp[n+1][halfSum+1];
        int i;
        for(i = 0 ; i <=halfSum; ++i) {
            dp[0][i] = false;
        }
        for(i = 0 ; i <= n; ++i) {
            dp[i][0] = true;
        }
        for(i = 1; i <= n; ++i) {
            for(int j = 1; j <= halfSum; ++j) {
                if(nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j - nums[i-1]] || dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][halfSum];
        
    }
};
