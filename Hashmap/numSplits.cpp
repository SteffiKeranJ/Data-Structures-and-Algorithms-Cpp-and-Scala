class Solution {
private: 
public:
    int numSplits(string s) {
        int n = s.size();
        if(n == 1) return 0;
        int count = 0;
        unordered_map<char, int>left;
        unordered_map<char, int>right;
        for(int i = 0; i < n; ++i) {
            right[s[i]]++;
        }
        for(int i = 0; i < n; ++i) {
            left[s[i]]++;
            right[s[i]]--;
            if(right[s[i]] == 0) right.erase(s[i]);
            if(left.size() == right.size()) count++;
        }
        return count;
    }
};
