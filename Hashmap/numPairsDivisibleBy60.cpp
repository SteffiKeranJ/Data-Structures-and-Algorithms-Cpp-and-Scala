class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        vector<int>rem(60);
        for(int t : time) {
            count+= rem[(60 - t % 60)%60];
            ++rem[t%60];
        }
        return count;
    }
};
