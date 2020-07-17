class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        //x 
        int x[8] = {-1, 1,0,0,-1,1,-1,1};
        //y
        int y[8]= {0, 0,1,-1,1,1,-1,-1};
        int row, col;
        // rows size
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> q;
        if(board[click[0]][click[1]]=='M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        if(board[click[0]][click[1]]=='E') {
            board[click[0]][click[1]] = 'B';
            // push the blank ones
            q.push(make_pair(click[0],click[1]));
        }
        while(!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop();
            int count = 0;
            for(int i = 0; i < 8; ++i) {
                row = temp.first + x[i];
                col = temp.second + y[i];
                
                if (row >= 0 && row < m && col >= 0 && col < n) {
                    // if there is a mine, increase the count
                    if (board[row][col] == 'M') count++;
                }
            }
            
            if (count == 0 ) {
                // explore the neighbours
                for(int i = 0; i < 8; ++i) {
                  row = temp.first + x[i];
                    col = temp.second + y[i];
                     if (row >= 0 && row < m && col >= 0 && col < n) {
                        if (board[row][col] == 'E') {
                            board[row][col] = 'B';
                            q.push(make_pair(row, col));
                        }
                     }
                }
            } else 
                // update the 'B' with the count of mines seen in the neighborhood
                board[temp.first][temp.second] = count + '0';
        }
        return board;
        
    }
};
