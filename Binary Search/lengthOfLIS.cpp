class Solution {
private:
    int findSmallest(vector<int>& subSeq, int target) {
        int l = 0;
        int r = subSeq.size();
        int mid;
        while(l < r) {
            mid = (l + r) >> 1;
            if(subSeq[mid] == target) return mid;
            if(subSeq[mid] < target) l = mid+1;
            else r = mid;
        }
        return l;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n =  nums.size();
        vector<int> subSeq;
        subSeq.push_back(nums[0]);
        int i, j;
        
        for(i = 1; i < n; ++i) {
            j = subSeq.size();
            if(subSeq[j-1] < nums[i]) subSeq.push_back(nums[i]);
            else {
                int idx = findSmallest(subSeq, nums[i]);
                subSeq[idx] = nums[i];
            }
        }
        return subSeq.size();
    }
};
