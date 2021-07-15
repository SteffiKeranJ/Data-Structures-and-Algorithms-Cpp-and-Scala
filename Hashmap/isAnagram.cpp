/**

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
**/


class Solution {
public:
    bool isAnagram(string s, string t) {
        int firstLength = s.size();
        int secondLength = t.size();
        // if lengths dont match return false
        if(firstLength != secondLength) return false;
        unordered_map<char, int> map;
        for(int i = 0; i < firstLength; ++i) {
            map[s[i]]++;
        }
        for(int i = 0; i < secondLength; ++i) {
            if(map.find(t[i])==map.end()) return false;
            map[t[i]]--;
        }
        for(auto j : map) {
            if(j.second != 0) return false;
        }
        return true;
    }
};
