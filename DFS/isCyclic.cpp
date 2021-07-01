/** 
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

For Input:
4 4
0 1
1 2
2 3
3 3
your output is: 
1
**/

class Solution
{
    public:
    int visited[100001] = {0};
    // 0 - > unvisited
    // 1 - > visiting
    // 2 - > visited
    
    bool DFS(int v, vector<int> adj[]) {
        if(visited[v]==1) return false;
        visited[v] = 1;
        for(int u = 0 ; u < adj[v].size(); ++u) {
            if(visited[adj[v][u]] == 0) {
                if(!DFS(adj[v][u], adj)) return false;
            }
            if(visited[adj[v][u]]==1) return false;
        }
        visited[v] = 2;
        
        return true;
    }
    
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	    for(int v = 0; v < V; ++v) {
	        if(visited[v]==0) {
	            if(!DFS(v, adj)) return 1;
	        }
	    }
	   	return 0;
	}
};
