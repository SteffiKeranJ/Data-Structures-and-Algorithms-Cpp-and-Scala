class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> decompressed;
        int i = 0;
        int f;
        int l = nums.size() - 1;
        for(; i < l; i = i+2) {
            f = nums[i];
            while(f--) {
                decompressed.push_back(nums[i+1]);
                }
            }                    
        
        return decompressed;
    };
};
