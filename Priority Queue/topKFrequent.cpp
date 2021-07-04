/**
347. Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
 
Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]


**/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        unordered_map<int, int> freqMap;
        for(int i = 0; i < n; ++i) {
            freqMap[nums[i]] += 1;
        }
        
        priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto i : freqMap) {
            pq.push(make_pair(i.second, i.first));
            if(pq.size() > k) pq.pop();
        }
       
        for(int i = 0; i < k; ++i) {
            if(!pq.empty())  {
                pair<int, int> top = pq.top();
                res.push_back(top.second);
                pq.pop();
            }
        }
        
        return res;
    }
};
