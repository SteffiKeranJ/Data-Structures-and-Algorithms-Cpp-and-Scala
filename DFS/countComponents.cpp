/** 
323. Number of Connected Components in an Undirected Graph

You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.

Return the number of connected components in the graph.


Example 1:


Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2
Example 2:


Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
Output: 1

T.C : O(E+V)
S.C : O(E+V)
**/

class Solution {
public:
    int visited[2001] = {0};
    void DFS(int u, vector<int>adj[]) {
        visited[u] = 1;
        for(int v = 0; v < adj[u].size(); ++v) {
            if(visited[adj[u][v]] == 0)
                DFS(adj[u][v], adj);
        }
        return;
    }
    
    
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[2001];
        int e = edges.size();
        for(int i = 0; i < e; ++i) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int counter = 0;
        for(int i = 0; i < n; ++i) {
            if(visited[i]==0) {
                counter++;
                DFS(i, adj);
            }
        }
        return counter;
    }
};
