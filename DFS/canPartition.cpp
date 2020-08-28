class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // find total sum
        int total = 0;
        int i = 0;
        int n = nums.size();
        for (; i < n; ++i) {
            total += nums[i];
        }
        
        // if total is odd, cannot be partitioned as equal sum subset
        if(total%2!=0) return false;
        int subSetSum = total/2;
        return dfs(nums, n-1, subSetSum);
    }
    map<int, bool> memo;
    bool dfs(vector<int> &nums, int n, int subSetSum) {
        if (!subSetSum) return true;
        if (!n || subSetSum < 0) return false;
        if(memo.find(subSetSum)!=memo.end()) {
            return memo[subSetSum];
        }
        bool result = dfs(nums, n-1, subSetSum - nums[n-1]) ||
            dfs(nums, n-1, subSetSum);
        memo[subSetSum] = result;
        return result;
    }
};
