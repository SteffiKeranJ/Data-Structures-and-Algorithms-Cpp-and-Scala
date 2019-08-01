class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int s = nums.size();
        if(s == 0) return vector<int>();
        vector<int>res(s+2, -1);
        for(int i = 0; i < s; i++) {
            res[nums[i]]++;
        }
        vector<int> ans;
        for(int i = 1; i <=s; i++) {
            if(res[i] == -1) ans.push_back(i);
        }
        return ans;
    }
};
