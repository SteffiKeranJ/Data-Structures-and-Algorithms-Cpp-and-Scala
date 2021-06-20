class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int i;
        for(i = 1; i < n; ++i) {
            if(intervals[i-1][1] >= intervals[i][0] ) {
                intervals[i][0] = intervals[i-1][0];
                intervals[i][1] = max(intervals[i][1], intervals[i-1][1]);
            } else {
                res.push_back(intervals[i-1]);
            }
        }
        res.push_back(intervals[i-1]);
        return res;
    }
};
