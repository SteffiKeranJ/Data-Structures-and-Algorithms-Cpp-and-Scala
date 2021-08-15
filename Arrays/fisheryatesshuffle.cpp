class Solution {
private:
    vector<int> original, random;
public:
    
    Solution(vector<int>& nums) {
        original = nums;
        random = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if(random.empty()) return random;
        int n = random.size();
        for(int i = n; i > 0; --i) {
            swap(random[i-1], random[rand()%i]);
        }
        return random;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
