class Solution {
private: 
    int countDigit(int n) {
        return int(log10(n)+1);
    }    
    
public:
    int findNumbers(vector<int>& nums) {
        int evenCount = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(countDigit(nums[i])%2 == 0) ++evenCount;
        }
        return evenCount;
    }
};
