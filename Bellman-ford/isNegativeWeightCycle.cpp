/**
Given a weighted directed graph with n nodes and m edges. Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
Note: edges[i] is defined as u, v and weight.
 

Example 1:

Input: n = 3, edges = {{0,1,-1},{1,2,-2},
{2,0,-3}}
Output: 1
Explanation: The graph contains negative weight
cycle as 0->1->2->0 with weight -1,-2,-3,-1.

**/
class Solution{
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> dist (n+1, INT_MAX);
	    vector<int> predecessor (n+1);
	    int E = edges.size();
	    dist[0] = 0;
	    for(int i = 1; i <= n-1; ++i) {
	        for(int j = 0; j < E; ++j) {
	            int u = edges[j][0];
	            int v = edges[j][1];
	            int weight = edges[j][2];
	            
	            if(dist[u]!=INT_MAX and dist[v] > dist[u] + weight) {
	                dist[v]  = dist[u] + weight;
	                predecessor[v] = u;
	            }
	        }
	    }
	    // find negative cycles;
	    for(int j = 0; j < E; ++j) {
	        int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];
	        if(dist[u]!=INT_MAX and dist[v] > dist[u] + weight) return 1;
	    }
	    return 0;
	    
	}
};
