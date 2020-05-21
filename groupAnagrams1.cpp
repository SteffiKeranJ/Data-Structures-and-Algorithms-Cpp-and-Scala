//Approach 1: sort and hashmap
//time:O(NKlogK)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        // using hashmap
        unordered_map<string, vector<string>> map;
        for(int i = 0; i < strs.size(); ++i) {
            // take every string and sort it
            string t = strs[i];
            sort(t.begin(), t.end());
            map[t].push_back(strs[i]);
        }
        for(auto j: map) {
            res.push_back(j.second);
        }
        return res;
    }
};

