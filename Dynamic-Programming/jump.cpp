/**
45. Jump Game II

Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

**/


class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
		for(int i = 1; i < n ; ++i) {
			int minimumStep = 9999999;
			for(int j = 0; j < i; ++j) {
				if(j+nums[j]< i) continue;
				else {
					minimumStep = min(minimumStep, 1+ dp[j]);
				}
			}
			dp[i] = minimumStep;
		}
		return dp[n-1] == 9999999 ? -1 : dp[n-1];
    }
};
