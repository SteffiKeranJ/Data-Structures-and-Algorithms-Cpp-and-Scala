/**
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
        
        if(n <=1) return 0;
        if(nums[0]==0 ) return -1;
        
        int maxReach = nums[0];
        int steps = nums[0];        
        int jumps = 1;
        
        for(int i = 1; i < n;++i) {
            if(i == n-1) return jumps;
            maxReach = max(maxReach, nums[i]+i);
            steps--;
            if(steps==0) {
                jumps++;
                if(i >= maxReach) return -1;
                steps= maxReach -i;
            }
        }
        return -1;
    }
};
