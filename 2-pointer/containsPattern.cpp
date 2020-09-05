class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int count = 0;
        int n = arr.size();
        int i = 0;
        for(; i+m < n; ++i) {
            if(arr[i]!=arr[i+m]) count = 0;
            count += (arr[i]==arr[i+m]);
            if(count == (k-1)*m) return true;
        }
        return false;
    }
};

