class Solution {
public:    

    int maxProfit(vector<int>& prices) {
        if (prices.size() <=1) return 0;
        int i, j;
        int maxi = 0;
        int minCp = INT_MAX;
        for (j = 0; j < prices.size(); j++) {
            minCp = min(minCp, prices[j]);
            maxi = max(maxi, prices[j]-minCp);
        }
        return maxi;
    }
};
