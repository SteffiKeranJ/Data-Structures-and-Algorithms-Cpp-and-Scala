class Solution {
public:
    void reverseString(vector<char>& s) {
      reversenow(s, 0, s.size()-1);
    }
    void reversenow(vector<char>& s, int start, int end) {
        if(start >=end) return;
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
    
        reversenow (s, start+1, end-1);
    }
};
