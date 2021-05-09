class Solution {
public:
    int max(int a, int b) {
        return a > b ? a:b;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int max_distance = 0;
        int i, j;

        for(i=0, j=0; i < n && j < m;) {
            if (i <=j && nums1[i] <= nums2[j]) {
                max_distance = max(max_distance, j - i);
                ++j;
            }
            else {
                ++i;
                ++j;
            }
        }
        return max_distance;
    }
};
