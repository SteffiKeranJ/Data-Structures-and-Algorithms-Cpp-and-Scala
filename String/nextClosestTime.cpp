class Solution {
public:
    string nextClosestTime(string time) {
        set<char> numSet;
        int n = time.size();
        for(int i = 0; i < n; ++i) {
            if(time[i] == ':') continue;
            numSet.insert(time[i]);
        }
        string res = time;
        
        for(int i = n-1; i >= 0; --i) {
            if(time[i] == ':') continue;
            auto it = numSet.find(time[i]);
            if(*it != *numSet.rbegin()) {
                it++;
                res[i] = *it;
                if((i >= 3 && stoi(res.substr(3, 2)) < 60) ||
                  ( i < 2 && stoi(res.substr(0, 2)) < 24 )) return res;
            }
            res[i] = *numSet.begin();
        }
        return res;
    }
};
