class MovingAverage {
public:
    /** Initialize your data structure here. */
    vector<int> numArray;
    int sum = 0;
    int windowsize;
    MovingAverage(int size) {
        windowsize = size;
    }
    
    double next(int val) {
        numArray.push_back(val);
        int n = numArray.size();
        sum+=val;
        int diff = n - windowsize;
        
        for(int i = 0; i < diff; ++i) {
            sum -= numArray[i];
            auto iterator= numArray.begin()+i;
            numArray.erase(iterator);
        }
        int divisor = n < windowsize ?n : windowsize;
        return (double) sum/divisor;
        
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
