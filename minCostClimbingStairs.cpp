class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int s = cost.size();
        for (int i = 2; i < cost.size(); i++) {
            cost[i]+=min(cost[i-1], cost[i-2]);
        }
        return min(cost[s - 1], cost[s-2]);
    }
};
