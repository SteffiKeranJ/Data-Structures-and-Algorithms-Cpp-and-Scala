/** 
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
**/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        vector<int> dp(n+1, 1);
        int maxLength = 1;
        int i, j;
        for(i = 1; i < n;++i) {
            j = i-1;
            while(j >= 0) {
                if(nums[j] < nums[i]) dp[i] = max(dp[i], 1 + dp[j]);
                --j;
            }
            
            maxLength = max(maxLength, dp[i]);
        }
        return maxLength;
        
    }
};

