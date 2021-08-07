class Solution {
public:
    vector<vector<int>> edges;
    vector<int> distance;
    int longest(int v) {
        if(distance[v] > 0) return distance[v];
        distance[v] = 1;
        for(auto neighbor: edges[v]) {
            distance[v] = max(distance[v], longest(neighbor)+1);
        }
        return distance[v];
    }
    
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> wordMap;
        int n = words.size();
        distance.clear();
        edges.clear();
        edges.resize(n);
        distance.resize(n);
        for(int i=0; i <words.size();++i) {
            wordMap[words[i]] = i;
        }
        for(int i = 0; i < words.size(); ++i) {
            int wn = words[i].size();
            string word = words[i];
            for(int j = 0; j < wn; ++j) {
                
                string newString = word.substr(0, j) +word.substr(j+1);
                auto it = wordMap.find(newString);
                if(it!=wordMap.end()) {
                    edges[it->second].push_back(i);
                }
            }
        }
        int answer = 0;
        for(int node = 0; node < n; ++node) {
            answer = max(answer, longest(node));
        }
        return answer;
    }
};
