class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return vector<vector<int>>{};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(merged.back()[1] < intervals[i][0])
                merged.push_back(intervals[i]);
            else {
                merged.back()[1] = merged.back()[1] > intervals[i][1]? merged.back()[1]: intervals[i][1];
            }
        }
        return merged;
    }
};
