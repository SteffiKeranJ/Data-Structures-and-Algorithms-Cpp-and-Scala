class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int n = nums.size();
        vector<int> m;
        for(int i = 0; i < n; ++i) {
           int rem = target - nums[i];
            if(map.find(rem)!= map.end()){
                m.push_back(map[rem]);
                m.push_back(i);
                return m;
            }
            map[nums[i]] = i;
        }
        return m;
    }
};
