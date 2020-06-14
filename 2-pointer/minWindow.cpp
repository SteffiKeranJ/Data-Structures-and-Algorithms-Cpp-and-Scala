class Solution {
public:
    string minWindow(string k, string t) {
        unordered_map<char, int> a, b;
        int m = k.size(), n = t.size();
        for(int i = 0; i < n; i++){
            b[t[i]]++;
        }
        
        int j = 0, e = 0;
        vector<int> c;
        for(int i = 0; i < m; i++){
            if(b[k[i]] != 0 && a[k[i]] < b[k[i]]){
                e++;
            }
            if(b[k[i]] != 0){
                a[k[i]]++;
            }
            if(e == n){
                while(a[k[j]] == 0 || a[k[j]] > b[k[j]]){
                    if(a[k[j]] > b[k[j]]){
                        a[k[j]]--;
                    }
                    j++;
                }
                if(c.empty() || c[1] - c[0] > i-j){
                    c = vector<int>{j, i};
                }
            }
        }
        if(c.empty()){
            string q;
            return q;
        }
        string l = k.substr(c[0], c[1]-c[0]+1);
        return l;
    }
};
