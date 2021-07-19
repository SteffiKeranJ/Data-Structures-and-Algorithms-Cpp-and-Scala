/** 
139. Word Break

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
**/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> visited(s.length(), false);
        int n = s.length();
        queue<int> q;
        q.push(0);
        int start, end;
        while(!q.empty()) {
            start = q.front();
            q.pop();
            if(visited[start] == true) continue;
            int end = start + 1;
            for(; end <= n; ++end) {
                if(wordSet.find(s.substr(start, end-start))!=wordSet.end()) {
                    q.push(end);
                    
                    if(end == n) return true;
                }
            }
            visited[start] = true;
        }
        return false;
        
    }
};
