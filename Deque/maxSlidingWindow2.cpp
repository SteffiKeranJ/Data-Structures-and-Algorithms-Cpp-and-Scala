class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> Q;
        vector<int>res;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(Q.size() && Q.front() < i+1 - k) Q.pop_front();
            while(Q.size() && nums[Q.back()] <= nums[i]) Q.pop_back();
            Q.push_back(i);
            if(i >= k-1) {
                res.push_back(nums[Q.front()]);
            }
        }
        return res;
    }
};
