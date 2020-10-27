class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> Q(k);
        int n = nums.size();
        int i;
        for( i =  0; i < k; ++i) {
            while(!Q.empty() && nums[i] >= nums[Q.back()]){
                // for every element the previous smaller ones are useless, remove them
                Q.pop_back();
            }
            Q.push_back(i);
        }
        for(; i < n; ++i) {
            // the element at the front is the largest one in the window
            ans.push_back(nums[Q.front()]);
            while(!Q.empty() && Q.front() <= i-k) {
                // Remove the elements which are out of the window
                Q.pop_front();
            }
            while ((!Q.empty()) && nums[i] >= nums[Q.back()]){
                Q.pop_back();
            }
            
            Q.push_back(i);
        }
       ans.push_back(nums[Q.front()]);
        return ans;
    }
};
