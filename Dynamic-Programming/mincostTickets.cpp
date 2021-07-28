class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = costs.size();
        int daysSize = days.size();
        unordered_set<int> daysSet;
        int lastDate = days[daysSize-1];
        for(int i = 0; i < daysSize; ++i) {
            daysSet.insert(days[i]);
        }
        
        int dp[366] = {0};
        for(int i = 1; i <= lastDate;++i) {
            dp[i] = INT_MAX;
        }
        for(int i = 1; i <= lastDate; ++i) {
            if(daysSet.find(i) == daysSet.end()) {
                dp[i] = dp[i-1];
            }
            dp[i] = min(dp[i], dp[i-1] + costs[0]);
            if(i - 7 >= 0) { // equals or exceeds a week
                dp[i] = min(dp[i], dp[i-7] + costs[1]);
            } else dp[i] = min(dp[i], costs[1]);
            if(i-30 >=0) {
                dp[i] = min(dp[i], dp[i-30] + costs[2]);
            } else dp[i] = min(dp[i], costs[2]);
        }
        return dp[lastDate];
    }
};
