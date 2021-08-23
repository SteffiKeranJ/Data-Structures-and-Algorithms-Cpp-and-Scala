class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n < m) return intersect(nums2, nums1);
        unordered_map<int, int> numsSet;
        vector<int> res;
        for(int el: nums1) numsSet[el]++;
        for(int el2: nums2) {
            if(numsSet.find(el2)!=numsSet.end()) {
                numsSet[el2]--;
                if(numsSet[el2] ==0) numsSet.erase(el2);
                res.push_back(el2);
            }
        }    
        return res;
    }
};
