/**
There is a new alien language that uses the English alphabet. However, the order among the letters is unknown to you.

You are given a list of strings words from the alien language's dictionary, where the strings in words are sorted lexicographically by the rules of this new language.

Return a string of the unique letters in the new alien language sorted in lexicographically increasing order by the new language's rules. If there is no solution, return "". If there are multiple solutions, return any of them.

A string s is lexicographically smaller than a string t if at the first letter where they differ, the letter in s comes before the letter in t in the alien language. If the first min(s.length, t.length) letters are the same, then s is smaller if and only if s.length < t.length.

 

Example 1:

Input: words = ["wrt","wrf","er","ett","rftt"]
Output: "wertf"
Example 2:

Input: words = ["z","x"]
Output: "zx"
Example 3:

Input: words = ["z","x","z"]
Output: ""
Explanation: The order is invalid, so return "".

Solution approach - Topological Sorting

**/

class Solution {
public:
    string res;
    stack<int> st;
    int visited[27] = {0};
    // 0 - > unvisited
    // 1 - > visiting
    // 2 - > visited
    bool topoSortUtil(int node, vector<int>adj[]) {
        if(visited[node] == 1) return false;
        visited[node] = 1;
        for(int v = 0; v < adj[node].size();++v) {
            if(visited[adj[node][v]] == 0) 
                if(!topoSortUtil(adj[node][v],  adj)) return false;
            if(visited[adj[node][v]] == 1) return false;
            
        }
        visited[node] = 2;
        st.push(node);
        return true;
    }
    
    
    string alienOrder(vector<string>& words) {
        vector<int>adj[27];
        int w = words.size();
        unordered_set<int>vertices;
        for(int i = 0; i < w; ++i) {
            for(int j = 0; j < words[i].size(); ++j) {
                vertices.insert(words[i][j]-'a');
            }
        }
        
        for(int i = 0; i < w-1; ++i) {
            int len1 = words[i].size();
            int len2 = words[i+1].size();
            int same  = 0;
            for(int j = 0; j < min(len1, len2); ++j) {
                if(words[i][j] == words[i+1][j]) { 
                    same++; 
                    continue;
                }
                if(words[i][j]!=words[i+1][j]) {
                    adj[words[i][j]-'a'].push_back(words[i+1][j]-'a');
                    break;
                } 
            }
            if(same == min(len1,len2) and len1 > len2) return "";
           
        }
        for(auto i= vertices.begin(); i != vertices.end() ; ++i) {
            
            if(visited[*i] == 0) {
                if(!topoSortUtil(*i, adj)) return "";
            }
        }

        while(!st.empty()){
            char top = 'a' + st.top();
            res += top;
            st.pop();
        
        }
        return res;
    }
};
