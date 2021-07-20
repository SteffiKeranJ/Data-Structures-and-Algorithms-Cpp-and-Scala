/**
49. Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lower-case English letters.
**/

class Solution {
public:
    string createHash(string s) {
        int counter[26] = {0};
        for(int i = 0; i < s.size(); ++i) {
            counter[s[i] - 'a']++;
        }
        string hash = "";
        for(int i = 0; i < 26; ++i) {
            hash+=("#" + to_string(counter[i]));
        }
        return hash;
        
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;
        vector<vector<string>> res;
        int n = strs.size();
        for(int i = 0; i < n; ++i) {
            string stringHash = createHash(strs[i]);
            cout << stringHash << endl;
            hashmap[stringHash].push_back(strs[i]);
        }
        for(auto it= hashmap.begin(); it != hashmap.end(); ++it) {
            res.push_back(it->second);
        }
        return res;
        
    }
};
