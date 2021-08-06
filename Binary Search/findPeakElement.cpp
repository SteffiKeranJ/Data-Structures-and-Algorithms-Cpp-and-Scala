class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1 ) return 0;
        if(n==2) return nums[0] >= nums[1] ? 0 : 1; 
        int low = 0;
        int high = n-1;
        int mid;
        while(low <= high) {
            mid = low + (high - low) /2;
            if((mid-1 >= 0 and nums[mid] > nums[mid-1]) && ( mid+1 < n and nums[mid] > nums[mid+1])) {
                return mid;
            } else if((mid-1 >= 0 and nums[mid-1] > nums[mid])) high = mid-1;
            else low = mid+1;
        }
        return low-1;
    }
};
