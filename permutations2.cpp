class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
     // permutation using heap's algorithm 
     vector<vector<int>>res;
    int n = nums.size();
    heapalgorithm(nums, n, n, res);
    return res;
    }
    
    void heapalgorithm(vector<int>& nums, int k, int n, vector<vector<int>>& res) {
        if(k == 1) {
            res.push_back(nums);
        }
        else {
            // perform permutations with kth unaltered
            heapalgorithm(nums, k-1, n, res);
            // generate permutations with kth swapped with each k-1 initial
            for(int i = 0; i < k-1; ++i) {
                // swap choice dependent on the parity of k
                if (k %2 == 0) { // k is even
                    swap(nums[i], nums[k-1]); // zero-indexed, the kth is at k-1
                } else {
                    swap(nums[0], nums[k-1]);
                }
                heapalgorithm(nums, k-1, n, res);
            }
        }
        
    }
};
