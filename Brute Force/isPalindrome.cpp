class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x%10 == 0 and x!=0)) return false;
        
        int reverted  =0 ;
        while(x >  reverted) {
            reverted = reverted*10 + (x%10);
            x/=10;
        }
        return x == reverted || x == reverted/10;    
    }
};
