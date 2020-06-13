class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        int i = 0;
        while(i < n && newInterval[1] >= intervals[i][0]) {            
            //if the interval ends before it begins
            // add it to the res
            if (intervals[i][1] < newInterval[0]) {
                res.push_back(intervals[i]);
            } else {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
            i++;
        }
        res.push_back(newInterval);
        while(i<n) res.push_back(intervals[i++]);
        return res;
    }
};
