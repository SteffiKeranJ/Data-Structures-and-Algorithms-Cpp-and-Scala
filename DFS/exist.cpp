class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()) return false;
        int rowlen = board.size();
        int collen = board[0].size();
        int i, j ;
        for (i = 0; i < rowlen; ++i ) {
            for (j = 0; j < collen; ++j ) {
                if (dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int row, int col, string&word, int index) {
        bool result;
        int i, j;

        if (index==word.size()) return true;
        
        
        if (row < 0 || row >=board.size() || col < 0 || col >=board[0].size() || board[row][col] != word[index])
            return false;
        if (board[row][col]=='0') return false;
        
      // board[row][col] = ''; // this creates error
        board[row][col] = '0';
       
        //Go to the adjacent 4 cells and see if the next letter is true.
        result  = dfs(board, row + 1, col, word, index + 1) || dfs(board, row , col + 1, word, index + 1) || dfs(board, row - 1, col, word, index + 1) || dfs(board, row , col - 1, word, index + 1);

        board[row][col] = word[index];
        
        return result;
    

    }
};
