class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    priority_queue<int, vector<int>, greater<int>>pq;
	    vector<int> res;
	    int i = 0;
	    for(; i <k; ++i) {
	        pq.push(arr[i]);
	    }
	    for(i=k; i < n ; ++i) {
	        if(arr[i] > pq.top()) {
	            pq.pop();
	            pq.push(arr[i]);
	        }
	    }
	    for(i = 0; i < k; ++i) {
	        res.push_back(pq.top());
	        pq.pop();
	    }
	    sort(res.begin(), res.end(), greater<int>());
	    return res;
	}

};
