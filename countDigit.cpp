class Solution {
private: 
    int countDigit(int n) {
        if(n == 0) return 0;
        return 1+countDigit(n/10);
    }    
    
public:
    int findNumbers(vector<int>& nums) {
        int evenCount = 0;
        for(int i = 0; i < nums.size(); ++i) {
            int no = nums[i];
            int t = countDigit(nums[i]);
            if(countDigit(nums[i])%2 == 0) ++evenCount;
        }
        return evenCount;
    }
};
