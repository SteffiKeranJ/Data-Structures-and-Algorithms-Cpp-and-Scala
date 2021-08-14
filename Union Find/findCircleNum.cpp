class Solution {
public:
    vector<int> parent;
    int find(int x) {
        return parent[x] == -1 ? x: find(parent[x]);
    }
    
    void unionH(int x, int y) {
        int xp= find(x);
        int yp = find(y);
        if(xp == yp) return;
        if(xp!=yp) parent[yp] = x;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces = 0;
        parent.resize(n, -1);
        for(int i=0; i < n;++i){
            for(int j = 0; j < n ;++j) {
               if(isConnected[i][j]) {
                   unionH(i,j);
               }
            }
        }
        for(int i=0; i < n;++i){
            if(parent[i] == -1) {
                provinces++;
            }
        }
        return provinces;
    }
};
