class Solution {
private:
    vector<int>adj[200001];
    unordered_set<int> visited;
public:
    void dfs(int start) {
        visited.insert(start);
        for(int neighbour: adj[start]) {
            if(visited.find(neighbour) == visited.end()) dfs(neighbour);
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        
        for(vector<int> edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(start);
        return visited.find(end)!=visited.end();
    }
};
