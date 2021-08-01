class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.size();
        int t = typed.size();
        bool isLong = false;
        int i, j;
        for(i = 0, j = 0; i < n; ) {
            if(name[i] == typed[j]) {
                ++i;
                ++j;
            } else if(j!=0 && (typed[j] == typed[j-1])) {
                ++j;
            } else {
                return false;
            }
        }
        if(j <= t-1) {
            for(; j < t; ++j) {
            if(typed[j] != name[n-1])  return false;
            }
        }
        
        return true;
    }
};
