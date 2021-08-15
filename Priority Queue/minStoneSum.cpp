class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq(piles.begin(), piles.end());
        int res = accumulate(piles.begin(), piles.end(), 0);
        
        while(k--) {
            int top = pq.top();
            int taken  = top >> 1;
            pq.pop();
            pq.push(top - taken);
            res -= taken;
        }
        return res;
    }
};
