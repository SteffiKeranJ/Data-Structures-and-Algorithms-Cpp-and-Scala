/**
Merge two binary Max heaps 
Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

Example 1:

Input  : 
n = 4 m = 3
a[] = {10, 5, 6, 2}, 
b[] = {12, 7, 9}
Output : 
{12, 10, 9, 2, 5, 7, 6}
**/

class Solution{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> merged;
        for(int i = 0; i < n; ++i) {
            merged.push_back(a[i]);
        }
        for(int i = 0; i < m; ++i) {
            merged.push_back(b[i]);
        }
        priority_queue<int> pq;
        for(int i = 0; i < merged.size(); ++i) {
            pq.push(merged[i]);
        }
        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};
