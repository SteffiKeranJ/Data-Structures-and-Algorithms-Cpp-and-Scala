class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = nums.size();
        int start, end;
        vector<int> res(2);
        int left = 0;
        int right = s;
        while(left < right) {
            int mid = left + (right-left)/2;
            if(nums[mid] >=  target) right = mid;
            else left = mid+1;
        }
        start = left;
        left  = 0; right = s;
        while(left < right) {
            int mid = left + (right-left)/2;
            if(nums[mid] >  target) right = mid;
            else left = mid+1;
        }
        end = left;
        return (start==end)? vector<int>{-1, -1} : vector<int>{start, end-1};
    }
};
