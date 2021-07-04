/** 

Leetcode 1514. Path with Maximum Probability

You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e

Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.

SOLUTION APPRROACH: DJIKSTRA'S
TIME COMPLEXITY: O ( V + E l o g V ) 

**/

class Solution {
public:
    void djikstraPath(vector<pair<int, double>> adj[], int totalNodes, int source, vector<double> &dist) {
        priority_queue<pair<double, int>,vector <pair<double, int>>> pq;
        pq.push(make_pair(1, source));
        dist[source] = 1;
        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            for(int v = 0; v < adj[u].size(); ++v) {
                int neighbour= adj[u][v].first;
                double weight = adj[u][v].second;
                if(dist[neighbour] < dist[u] * weight) {
                    dist[neighbour] = dist[u] * weight;
                    pq.push({dist[neighbour],neighbour});
                }
            }
        }
    }
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int, double>> adj[n];
        vector<double> dist(n, 0);
        int i;
        for(i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
            adj[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
        }
        djikstraPath(adj, n, start, dist);
        return dist[end];
    }
};
