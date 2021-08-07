class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int n = asteroids.size();
        for(int ast :  asteroids) {
            if(ast > 0) {
                s.push(ast);
            } else{
                if(s.empty() || s.top() < 0) {
                    s.push(ast);
                } else {
                    while(!s.empty()) {
                        int top = s.top();    
                        if(-top > ast and -top < 0) {
                           s.pop();
                            if(s.empty()) {
                                s.push(ast);
                                break;
                            }
                        }
                        else if(-top == ast and -top < 0) {
                            s.pop();
                            break;
                        }
                        else if(-top > 0) {
                          s.push(ast);
                            break;
                        } 
                        else break;
                    }
                }
            }
        }
        vector<int> res;
        if(s.empty()) return res;
        while(!s.empty()) {
            int top = s.top();
            res.push_back(top);
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
