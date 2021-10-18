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
private:
    vector<int> adj[2001];
    set<int> visited;
    
    bool dfs(int node,int parent) {
        if(visited.find(node) != visited.end()) return false;
        visited.insert(node);
        
        for(auto e: adj[node]) {
            if(parent!=e) {
                if(!dfs(e, node)) return false;
            }
        }
        return true;
    }
    
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n==1) return true;
        visited = set<int>();
        for(auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }        
        return dfs(0, -1) and visited.size()==n;             
    }
};
