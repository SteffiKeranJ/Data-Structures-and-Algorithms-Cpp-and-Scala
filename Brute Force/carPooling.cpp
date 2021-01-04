class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int stops[1001] = {};
        int i;
        int n = trips.size();
        for(i =0 ; i < n; ++i) {
            stops[trips[i][1]] += trips[i][0];
            stops[trips[i][2]] -= trips[i][0];
        }
        int passengers = 0;
        for(i = 0; capacity>=0 && i < 1001; ++i) {
           passengers += stops[i];
        if(passengers > capacity)
                return false;
        }
        return true;
    }
};
