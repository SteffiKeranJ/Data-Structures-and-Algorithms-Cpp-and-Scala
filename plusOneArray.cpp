class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int s = digits.size();
        int carry = 1;
        if(digits[s-1] < 9){
          digits[s-1]+=1;
            return digits;
        }
        for(int i = s-1; i >=0; i--) {
            int temp = digits[i]+carry; 
            digits[i] = temp%10; // when the sum has carry
            carry = temp/10;
        }
        if(digits[0] == 0) { // leading zeros are not allowed
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }    
};
