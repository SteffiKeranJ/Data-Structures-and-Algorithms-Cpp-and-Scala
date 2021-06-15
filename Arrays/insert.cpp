int max(int a , int b ) {
    return a > b ? a: b;
}

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    intervals.push_back(newInterval);
    std::sort(intervals.begin(), intervals.end(),
            [](const Interval &x, const Interval &y) {
                return x.start < y.start;
            });
    int n = intervals.size();
    
    vector<Interval> res;
    int i;
    for(i = 1; i < n; ++i) {
        if(intervals[i].start <= intervals[i-1].end)  {
            intervals[i].start = intervals[i-1].start;
            intervals[i].end = max(intervals[i-1].end, intervals[i].end);
        }
        else {
            res.push_back(intervals[i-1]);
        }
    }
    res.push_back(intervals[n-1]);
    
    return res;
}
