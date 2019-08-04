class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int s1 = num1.length()-1;
        int s2 = num2.length()-1;
        int carry = 0;
        int sum;
        while(s1>=0 || s2>=0 || carry) {
            sum = 0;
            if(s1>=0) {
                sum+=num1[s1] - '0';
                s1--;
            }
            if(s2>=0) {
                sum+=num2[s2] - '0';
                s2--;
            }
            sum+=carry;
            carry = sum/10;
            ans+=to_string(sum%10);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
