class Solution {
public:
    int popbits(int x) {
        int count = 0;
        for(; x!=0; count++) {
            x &=x-1;
        }
        return count;
    }
    
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i = 0; i <= n;++i) {
            res.push_back(popbits(i));
        }
        return res;
    }
};
