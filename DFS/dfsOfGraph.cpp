/**
Given a connected undirected graph. Perform a Depth First Traversal of the graph.

**/

class Solution 
{
    public:
    	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int>res;
	    DFS(adj, V, res);
	    return res;
	}
	
    void DFS(vector<int> adj[], int V, vector<int>&res)
    {
        vector<bool> visited(V, false);
        for (int u=0; u<V; u++)
            if (visited[u] == false)
                DFSUtil(u, adj, visited, res);
    }	
    
	void DFSUtil(int V, vector<int> adj[], vector<bool>& visited, vector<int>& res) {
	    res.push_back(V);
	    visited[V] = true;
        for(int u = 0; u < adj[V].size();++u) {
            if(visited[adj[V][u]] == false) DFSUtil(adj[V][u], adj, visited, res);
        }
	    
	}
	
};
