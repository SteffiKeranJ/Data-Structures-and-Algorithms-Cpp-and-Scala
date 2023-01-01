```
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true

Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false

Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false

```

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charHmap;
        unordered_map<string, char> stringHmap;
        int patternLength = pattern.size();
        vector<string> sVector =  split(s, ' ');
        int n = sVector.size();
        if(patternLength!=n) return false;

        for(int i = 0; i < n; ++i) {
            
            if(charHmap.find(pattern[i]) != charHmap.end()) {
                if(charHmap[pattern[i]] != sVector[i]) return false;
            }
            if(stringHmap.find(sVector[i]) != stringHmap.end()) {
                if(stringHmap[sVector[i]] != pattern[i]) return false;
            }
            if(charHmap.find(pattern[i]) == charHmap.end()) 
                charHmap[pattern[i]] = sVector[i];
            
            if(stringHmap.find(sVector[i]) == stringHmap.end()) 
                stringHmap[sVector[i]] = pattern[i];
        }
        return true;
    }

private:
    vector<string> split(string s, char delim) {
        vector<string> res;
        s = s.substr(0, s.length());
        stringstream ss(s);
        string segment;
        while(getline(ss, segment, delim)) {
            res.push_back(segment);
        }
        return res;
    }
};
