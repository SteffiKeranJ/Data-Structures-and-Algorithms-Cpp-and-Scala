/**
GFG - Detect cycle in an undirected graph 
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 

For Input:
5 5
0 4
1 2
1 4
2 3
3 4
your output is: 
1 (cycle is present)

**/
class Solution 
{
    public:
    int visited[100001] = {0};
    // 0 - > unvisited
    // 1 - > visiting
    // 2 - > visited
    
    bool DFS(int v, vector<int> adj[], int parent) {
        visited[v] = 2;
        for(int u = 0 ; u < adj[v].size(); ++u) {
            if(visited[adj[v][u]] == 0) {
                if(!DFS(adj[v][u], adj, v)) return false;
            }
            else if(adj[v][u]!=parent) return false;
        }

        return true;
    }
    
	//Function to detect cycle in a directed graph.
	bool isCycle(int V, vector<int> adj[]) 
	{
	    for(int v = 0; v < V; ++v) {
	        if(visited[v]==0) {
	            if(!DFS(v, adj, -1)) return 1;
	        }
	    }
	   	return 0;
	}
};
