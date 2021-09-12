class Solution {
private:
    int n;
    unordered_map<string, bool> memo;
    int targetSum;
public:
    bool backtrack(vector<int>& arr, int index, int count, int currSum, int k, string& taken) {        
      
        // We made k - 1 subsets with target sum and last subset will also have target sum.
        if (count == k - 1) { 
            return true;
        }
        
        // No need to proceed further.
        if (currSum > targetSum) { 
            return false;
        }
        
        // If we have already computed the current combination.
        if (memo.find(taken) != memo.end()) {
            return memo[taken];
        }
      
        // When curr sum reaches target then one subset is made.
        // Increment count and reset current sum.
        if (currSum == targetSum) {
            return memo[taken] = backtrack(arr, 0, count + 1, 0, k,  taken);
        }
        
        // Try not picked elements to make some combinations.
        for (int j = index; j < n; ++j) {
            if (taken[j] == '0') {
                // Include this element in current subset.
                taken[j] = '1';
                
                // If using current jth element in this subset leads to make all valid subsets.
                if (backtrack(arr, j + 1, count, currSum + arr[j], k,  taken)) {
                    return true;
                }
                
                // Backtrack step.
                taken[j] = '0';
            }
        } 
      
        // We were not able to make a valid combination after picking each element from the array,
        // hence we can't make k subsets.
        return memo[taken] = false;
    }
  
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalArraySum = 0;
        n = nums.size();

        for (int num: nums) {
             totalArraySum += num;
        }
      
        // If total sum not divisible by k, we can't make subsets.
        if (totalArraySum % k != 0) { 
            return false;
        }
      
        // Sort in decreasing order.
        sort(nums.begin(), nums.end(), greater<int>());
        
        targetSum = totalArraySum / k;
        
        // String to represent taken array.
        string taken(n, '0');
        
        return backtrack(nums, 0, 0, 0, k,  taken);
    }
};
