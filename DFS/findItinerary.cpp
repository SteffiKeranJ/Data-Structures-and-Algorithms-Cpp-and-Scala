class Solution {
private:
    map<string, multiset<string>> target;
    vector<string> route;
    
    void visit(string airport) {
        while(target[airport].size()) {
            string next = *target[airport].begin();
            target[airport].erase(target[airport].begin());
            visit(next);
        }
        route.push_back(airport);
    }    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto ticket: tickets) {
            target[ticket[0]].insert(ticket[1]);
        }
        
        visit("JFK");
        return vector<string>(route.rbegin(), route.rend());
    }

};
