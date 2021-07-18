/** 
15. 3Sum
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

**/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-1; ++i) {
            
            // skip duplicate values;
            if(i!=0 && nums[i]==nums[i-1]) continue;
            if(nums[i] > 0) break;
            int lo = i+1;
            int hi = n-1;
            while(lo < hi) {
                int tempSum = nums[i] + nums[lo] + nums[hi];
                if(tempSum > 0) hi--;
                else if(tempSum < 0) lo++;
                else {
                    res.push_back({nums[i], nums[lo], nums[hi]});
                    lo++;
                    hi--;
                    while(lo < hi && nums[lo] == nums[lo-1])
                        lo++;
                }
            }
        }
        return res;
    }
};
