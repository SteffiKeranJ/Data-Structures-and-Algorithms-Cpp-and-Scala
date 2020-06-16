class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // check if the string is empty
        int n = s.length();
        int longSubstr  = 0;
        // initialize the pointers
        int left = 0;
        int right  = 0;
        // initialize the hashmap
       unordered_map<char, int> map;
        // start the window
        while(right < n) {
            // check if the char at 'j' aka 'right' is in the map
            int sright = s[right];
            map[sright]++;
            // increase the window
            right++;
            // condition to see if u encounter a duplicate value
            // so remove left character
            while(map[sright] > 1) {
                // remove the left char to ensure the substring is unique
                map[s[left++]]--;
            }
            // compare for the longest substring
            longSubstr = max(longSubstr, right - left);    
        }
        return longSubstr;
    }  
};
