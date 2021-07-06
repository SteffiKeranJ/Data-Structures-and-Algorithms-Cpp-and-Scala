/**
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
**/


class Solution {
public:
    void djikstra(vector<pair<int,int>> adjList[], int u, vector<int>& dist, int n) {
        // min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        dist[u] = 0;
        pq.push({0, u});
        while(!pq.empty()) {
            // take the vertex from min heap's top
            int u = pq.top().second;
            pq.pop();
            for(int v = 0; v < adjList[u].size(); ++v) {
                int neighbour = adjList[u][v].first;
                int weight = adjList[u][v].second;
                if(dist[neighbour] > dist[u] + weight) {
                    dist[neighbour] = dist[u] + weight;
                    pq.push(make_pair(dist[neighbour], neighbour));
                }
            }
            
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int t = times.size();
        vector<pair<int,int>> adjList[n+1];
        // Step 1: Create the Adjacency List
        for (int i = 0; i < t; ++i) {
            adjList[times[i][0]].push_back(make_pair(times[i][1], times[i][2]));
        }
        // Distance table
        vector<int> dist(n+1, INT_MAX);
        // Step 2: Start Djikstra algorithm
        djikstra(adjList, k, dist, n);
        int res = *max_element(dist.begin()+1, dist.end());
        return res == INT_MAX ? -1 : res;
    }
};
