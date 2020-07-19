class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int finishTime = 0;
        vector<vector<int>> adjlist (n, vector<int>());
        
        for(int i = 0; i < n; ++i) {
            if(manager[i] == -1) continue;
            adjlist[manager[i]].push_back(i);
        }
        
        // first int is employee id
        // second int is time taken to inform them
        queue<pair<int, int>> q;
        
        q.push({headID, 0});
        while(!q.empty()) {
            pair<int, int> currEmpl;
            currEmpl = q.front();
            q.pop();
            int curEid = currEmpl.first;
            int curInformTime = currEmpl.second + informTime[curEid];

            finishTime = max(finishTime, curInformTime);
            
            for(auto nextEmpl : adjlist[curEid]) 
                q.push({nextEmpl, curInformTime});
        }
        return finishTime;
    }
    
    int max(int a, int b) {
        return a > b ?a : b;
    }
};
