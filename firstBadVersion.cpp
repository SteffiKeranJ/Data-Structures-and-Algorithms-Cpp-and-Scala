bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n==0) return -1;
        int left = 1;
        int right = n;
        while(left < right) {
            int mid = left + (right-left)/2;
            if(isBadVersion(mid) == true) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};
