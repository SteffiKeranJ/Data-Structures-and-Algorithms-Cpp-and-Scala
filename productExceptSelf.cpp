class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> outputArr(N);
        outputArr[0] = 1;
        // parsing from left to right
        int i = 1;
        for(;i < N;++i) {
            outputArr[i] = outputArr[i-1] * nums[i-1];
        }
        int R = 1;
         i = N-1;
        for(; i >=0; --i) {
            outputArr[i] = outputArr[i] * R;
            R = R*nums[i];
        }      
        return outputArr;
    }
};
