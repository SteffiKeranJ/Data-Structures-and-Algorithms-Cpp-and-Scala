// using counter
// time: O(NK)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        // using hashmap
        unordered_map<string, vector<string>> map;
        for(int i = 0; i < strs.size(); ++i) {
            int counter[26] = {0};
            string t;
            for(char c:strs[i]) {
                counter[c-'a']++;
            }
            for(int k = 0; k < 26; ++k) {
                t += string(counter[k], k + 'a');
            }
            
            map[t].push_back(strs[i]);
        }
        for(auto j: map) {
            res.push_back(j.second);
        }
        return res;
    }
};
// time complexity: O(NK)
