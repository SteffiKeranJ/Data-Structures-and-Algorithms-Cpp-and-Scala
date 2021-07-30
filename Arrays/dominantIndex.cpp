class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest = nums[0];
        int largestIndex = 0;
        int n = nums.size();
        if(n == 1) return 0;
        for(int i = 1; i < n; ++i) {
            if(nums[i] > largest) {
                largestIndex = i;
                largest = nums[i];
            }
        }
        for(int i = 0; i < n; ++i) {
            if(nums[i] * 2 > largest && i != largestIndex) return -1;
        }
        return largestIndex;
    }
};
