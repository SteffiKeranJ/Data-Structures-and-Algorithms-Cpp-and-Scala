/** 
Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
**/
class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
    bool visited[10001] = {0};
    void BFS(int v, vector<int> adj[], vector<int>& res) {
        visited[v] = 1;
        queue<int> q;
        q.push(v);
        while(!q.empty()) {
            int s = q.front();
            q.pop();
            res.push_back(s);
            for(int u = 0; u < adj[s].size(); ++u) {
                if(visited[adj[s][u]] == 0) {
                    visited[adj[s][u]] = 1;
                    q.push(adj[s][u]);
                }
            }
        }
    }
    
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int> res;
	    BFS(0, adj, res);
	    return res;
	}
};
