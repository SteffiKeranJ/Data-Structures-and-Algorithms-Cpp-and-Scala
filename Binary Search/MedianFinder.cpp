class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> store;
    MedianFinder() {
        
    }
    
   
    void addNum(int num) {
        if(store.empty()) store.push_back(num);
        else {
            store.insert(lower_bound(store.begin(), store.end(), num), num);
        }
    }
    
    double findMedian() {
        int n = store.size();
        return (n&1 ? store[n>>1]: ((double) store[(n>>1)-1] + store[n>>1])*0.5);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
