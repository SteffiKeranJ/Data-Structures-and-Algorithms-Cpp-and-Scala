// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int binarySearch(int low, int high) {
        if(low < high) {
            int mid =  low + ((high-low)>>1);
            if(isBadVersion(mid)) return binarySearch(low,mid);
            else return binarySearch(mid+1, high);
        }
            
        return low;
        
    }
    
    int firstBadVersion(int n) {
        return binarySearch(1, n);
    }
};
