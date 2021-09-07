class Solution {
private:
    vector<vector<int>> res;
public:
    void helper(vector<vector<int>>& graph, int curr, int destination, vector<int>&temp) {
        temp.push_back(curr);
        if(curr == destination) res.push_back(temp);
        else {
            for(int neighbor: graph[curr]) {
                helper(graph, neighbor, destination, temp);
                if(!temp.empty())temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        res.clear();
        vector<int> temp;
        int n = graph.size();
        helper(graph, 0, n-1, temp);
        return res;
    }
};
