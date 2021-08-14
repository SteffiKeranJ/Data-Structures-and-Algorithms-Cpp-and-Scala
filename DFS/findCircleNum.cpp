class Solution {
public:
    set<int> nodeSet;
    
    void DFS(int i, vector<vector<int>>& isConnected) {
        for(int j = 0; j < isConnected.size(); ++j) {
            if(isConnected[i][j] == 1 && nodeSet.find(j) ==nodeSet.end()) {
                nodeSet.insert(j);
                DFS(j, isConnected);
            }
        }
        return;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        for(int i = 0; i < n; ++i) {
           if(nodeSet.find(i) == nodeSet.end()) {
               count++;
               DFS(i, isConnected);               
           }
        }
        return count;
    }
};
