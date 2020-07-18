class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int x[4] = {0,0,1,-1};
        int y[4] = {-1,1,0,0};
        int r;
        int c;
        int m  = rooms.size();
        if(m == 0) return;
        const int GATE = 0;
        const int EMPTY = INT_MAX;
        const int WALL = -1;
        int n = rooms[0].size();
        if (n == 0 ) return;
        queue<pair<int, int>> q;
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                // only the gates are considered as start nodes
                // it is like from gate to other nodes, distance is computed
                if (rooms[row][col] != GATE) continue;
                q.push({row,col});
            }
        }
       
        while(!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop();
            int u = temp.first;
            int v = temp.second;
            int dist = rooms[u][v]+1;

            for(int i = 0; i < 4; ++i) {
                r = u + x[i];
                c = v + y[i];
                if (r < 0 || r >= m) continue;
                if(c < 0 || c>= n) continue;
                if(rooms[r][c] != EMPTY) continue; // if it is a wall, skip
                rooms[r][c] = dist;
                q.push({r ,c});
                // if (rooms[r][c] == EMPTY) {
                //     rooms[r][c] = dist;
                //     q.push({r ,c});
                // }

            }
        }
        
    }
};
