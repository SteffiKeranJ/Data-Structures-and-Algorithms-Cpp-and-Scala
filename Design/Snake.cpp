class SnakeGame {
private:
    vector<vector<int>> grid;
    
    queue<pair<int, int>> q;
    queue<pair<int, int>> snakeBody;
    unordered_map<string, pair<int, int>> dir = {
        {"U", {-1,0}},
        {"D", {1,0}},
        {"L", {0, -1}},
        {"R", {0,1}}
    };
    int posR, posC;
    int totalLength = 0; // snakeLength
public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        grid  =vector<vector<int>>(height, vector<int>(width,0));
        for(auto f: food) 
            q.push({f[0], f[1]});
        
        // initially the snake is at {0, 0}
        posR = 0; posC = 0;
        snakeBody.push({posR, posC});
        
        totalLength = 0;
    }
    
    int move(string direction) {
        int newR = posR+ dir[direction].first;
        int newC = posC+ dir[direction].second;
        // return -1 if out of boundary or the grid cell is occupied
        if(newR>=grid.size() || newC>=grid[0].size() || newR<0 || newC<0|| grid[newR][newC] ) return -1;
        auto foodPos = q.front();
        if(newR == foodPos.first and newC == foodPos.second) {
            totalLength++; 
            q.pop();
        }
        snakeBody.push({newR, newC});
        grid[newR][newC] = 1; // because the snake's body is occupying this cell
        
        if(snakeBody.size() >  totalLength) {
            auto firstCell = snakeBody.front();
            grid[firstCell.first][firstCell.second]=0;// reset
            snakeBody.pop();
        }
        
        posR = newR;
        posC = newC;
        return totalLength;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
