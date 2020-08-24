class Solution {
public:
    int characterReplacement(string s, int k) {
        int window_start = 0;
        int window_end = 0;
        int max_change = 0;
        int maxlength = 0;
        int N = s.length();
        int countChar[26] = {0};
        for(; window_end < N; ++window_end ) {
            countChar[s.at(window_end)-65]++;
            max_change = max(max_change, countChar[s.at(window_end)-65]); 
            if((window_end - window_start+1) -max_change > k) {
                maxlength = max(maxlength, window_end-window_start);
                countChar[s.at(window_start)-'A']--;
                window_start++;
            }
        }
        
        return  max(maxlength, window_end-window_start);
    }
    
    int max(int a, int b) {
        return a > b ? a:b;
    }
};
