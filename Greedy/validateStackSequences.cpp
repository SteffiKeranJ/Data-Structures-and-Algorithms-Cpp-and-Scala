class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int N =  pushed.size();
        int j =0;
        for(int i :  pushed) {
            s.push(i);
            while(!s.empty() && j < N && s.top()==popped[j]){
                j++;
                s.pop();
            }
        }
        return j == N;
    }
};
