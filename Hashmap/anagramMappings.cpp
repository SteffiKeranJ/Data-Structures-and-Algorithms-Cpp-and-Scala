class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> numsMap;
        int n = nums2.size();
        for(int i = 0; i < n; ++i) {
            numsMap[nums2[i]] = i;
        }
        for(int i = 0; i < n;++i) {
            res.push_back(numsMap[nums1[i]]);
        }
        return res;
        
    }
};
