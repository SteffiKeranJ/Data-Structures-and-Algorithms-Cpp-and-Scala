/**
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
**/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return true;
        if(nums[0] == 0) return false;
        int maxReach = nums[0];
        int steps = nums[0];
        for(int i = 1; i < n; ++i) {
            if(i == n-1) return true;
            maxReach = max(maxReach, nums[i]+i);
            if(i >= maxReach) return false;
            steps--;
            if(steps == 0) {
                steps = maxReach - i;
            }
        }
        return false;      
    }
};
