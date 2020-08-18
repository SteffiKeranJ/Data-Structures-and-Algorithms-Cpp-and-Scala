class Solution {
public:
    int minOperations(int n) {
        int r=0;

        int min = 1;
        int max = (2*(n-1))+1;
        int eq = (max + min)/2;
        
        for(int j = 0; j < n/2; ++j) {
            r += eq - (2*j+1);
        }
        return r;
    }
};
