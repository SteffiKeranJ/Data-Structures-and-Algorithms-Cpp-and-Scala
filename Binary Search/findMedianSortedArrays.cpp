class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = nums1.size() - 1;
        int pos = n - 1;
        while (p1 >= 0 && pos >= 0) {
            if (nums1[p1] < nums2[pos]) {
                nums1[p2] = nums2[pos];
                p2--;
                pos--;
            } else {
                nums1[p2] = nums1[p1];
                p2--;
                p1--;
            }
        }
        while (pos >= 0) {
            nums1[p2] = nums2[pos];
            p2--;
            pos--;
        }
        
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int numZeroes = nums2.size();
        int m = nums1.size();
        while (numZeroes--) {
            nums1.push_back(0);
        }
        merge(nums1, m, nums2, nums2.size());
        if (nums1.size() % 2) {
            return (nums1[nums1.size() / 2]);
        } else {
            return (double) (nums1[nums1.size() / 2 - 1] + nums1[nums1.size() / 2]) / 2;
        }
    }
};
