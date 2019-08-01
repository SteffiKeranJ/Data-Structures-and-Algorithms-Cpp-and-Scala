class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        queue<char> q;
        vector<int> v(2);
        int count = 0;
        int x; int y;
        for(int i = 0; i < S.length(); i++){
            if(q.empty()) {
                q.push(S[i]);
                v[0] = i;
                v[1] = i;
            } 
            else if (q.front() == S[i]) {
                v[1] = i;
            } else if(q.front()!= S[i]) {
                q.pop();
                if (v[1]-v[0]>1) res.push_back(v);
                q.push(S[i]);
                v[0] = i;
                v[1] = i;
            }
        }
        if(v[1]-v[0]>1) res.push_back(v);
        return res;
    }
};
