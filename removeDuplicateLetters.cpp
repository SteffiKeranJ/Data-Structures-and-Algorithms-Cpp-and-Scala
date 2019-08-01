// Uses a vector to fake a stack
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> dict(256, 0);
        vector<bool> visited(256, false);
        string res="";
        for(auto ch: s) dict[ch]++;
        for(auto ch: s) {
            dict[ch]--;
            if(visited[ch]) continue;
            while(ch < res.back() && dict[res.back()]) {
                visited[res.back()] = false;
                res.pop_back();
            }
            res+=ch;
            visited[ch] = true;
        }
        return res;
            
    }
};
