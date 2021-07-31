/** 

261. Graph Valid Tree

You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph.

Return true if the edges of the given graph make up a valid tree, and false otherwise.

 

Example 1:


Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
Output: true
Example 2:


Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
Output: false
 

Constraints:

1 <= 2000 <= n
0 <= edges.length <= 5000
edges[i].length == 2
0 <= ai, bi < n
ai != bi
There are no self-loops or repeated edges.

**/


class Solution {
public:
    int visited[2001]={0};    
    vector<int> adjList[10001];
    bool DFS(int u, int parent) {
        if(visited[u] == 1) return false;
        visited[u] = 1;
        for(int v  = 0; v < adjList[u].size(); ++v) {
            if(adjList[u][v]!=parent) {
                if(!DFS(adjList[u][v], u)) return false;
            }
        }
        return true;         
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        int e = edges.size();
        if(e == 0 && n == 1) return true;
        if(e != n-1) return false;
        for(int i = 0; i < e; ++i){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i = 0; i < n; ++i) {
            if(visited[i]==0) {
                if(!DFS(i, -1)) return false;
            }
        }
        return true;
    }
};
