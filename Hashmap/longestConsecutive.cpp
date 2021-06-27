/**

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

**/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxCount = 0;
        int N = nums.size();
        unordered_map<int, bool>map;
        for(int i = 0; i < N; ++i) {
            map[nums[i]] = true;
        }
        for(int i = 0; i < N; ++i) {
            int count =0;
            if(map.find(nums[i]-1) == map.end()) {
                int j = nums[i]+1;
                count = 1;
                while(map.find(j) != map.end()) {
                    count+=1;
                    ++j;
                }
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};
