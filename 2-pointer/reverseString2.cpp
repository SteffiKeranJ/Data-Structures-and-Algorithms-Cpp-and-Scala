class Solution {
public:
    void reverseString(vector<char>& s) {
        int left;
        int right;
        for(left = 0, right = s.size()-1; right >=left ; ) {
            char temp = s[right];
            s[right] = s[left];
            s[left] = temp;
            ++left;
            --right;
        }
    }
};
