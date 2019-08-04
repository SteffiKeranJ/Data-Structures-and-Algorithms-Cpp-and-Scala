// Brute force
class Solution {
public:
    bool judgeCircle(string moves) {
        int res = 0;
        for(int i = 0 ; i < moves.length(); i++) {
            if(moves[i] == 'U') res+=1;
            else if(moves[i] == 'D') res-=1;
            else if(moves[i] == 'L') res+=2;
            else if(moves[i] == 'R') res-=2;
            else return false;
        }
        if(res==0) return true;
        return false;
    }
};
// Time complexity: O(n)
// Space complexity: O(1)
