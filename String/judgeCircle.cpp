class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size();
        if(n == 1) return false;
        int L = +1;
        int R = -1;
        int U = +2;
        int D = -2;
        int horizontalsum = 0;
        int verticalsum = 0;
        
        for(int i = 0; i < n; ++i) {
            if(moves[i] == 'L') horizontalsum += L;
            if(moves[i] == 'R') horizontalsum += R;
            if(moves[i] == 'U') verticalsum += U;
            if(moves[i] == 'D') verticalsum += D;
        }
        return horizontalsum == 0 && verticalsum == 0;
        
    }
};
