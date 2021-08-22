class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    int kVal;
    KthLargest(int k, vector<int>& nums) {
        pq = {};
        kVal= k;
        for(int num: nums) pq.push(num);
        while(pq.size() > kVal) pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > kVal) pq.pop();      
        return pq.top();            
    }
};
