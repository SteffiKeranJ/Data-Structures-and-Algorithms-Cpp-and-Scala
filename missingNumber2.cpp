class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max = nums.back(); // to find the last element
        vector<int>res(max+2, -1);
        for(int x: nums) {
            res[x]++;
        }
        for(int x = 0; x < res.size(); x++) {
            if (res[x] == -1) return x;
        }
        return -1;
    }
};
