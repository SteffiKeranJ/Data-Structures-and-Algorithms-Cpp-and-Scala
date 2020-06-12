class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort it -> O(nlgn) time
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        if(intervals.size() == 0)
            return res;
         int f = intervals[0][0];
        int s = intervals[0][1];
        for(int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][0] <= s) {
                if(intervals[i][1] > s) {
                    s = intervals[i][1];
                }
            } else {
                res.push_back({f, s});
                f = intervals[i][0];
                s= intervals[i][1];
            }
        }
        res.push_back({f,s});
        return res;
    }
};
