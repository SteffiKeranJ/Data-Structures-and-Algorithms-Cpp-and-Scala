class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, Employee*> emplMap; 
        for (auto &e : employees){
            emplMap[e->id] = e;
        }
        return dfs(emplMap, id);
    }
    
    int dfs(map<int, Employee*>& em, int id){
        int sum = em[id]->importance;
        for(auto &subord: em[id]->subordinates) {
            sum += dfs(em, subord);
        }
        return sum;
    }
};
