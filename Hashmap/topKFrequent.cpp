class Solution {
public:
    struct comparator {
        bool operator()(const pair<int, string>& lhs, const pair<int, string>& rhs) const {
            if (lhs.first != rhs.first)
                return lhs.first < rhs.first;
            return lhs.second > rhs.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> map;
        vector<string> res;
        int maxF = 0;
        
        for(int i = 0; i < words.size(); ++i) {
            std::unordered_map<string,int>::iterator it = map.find(words[i]);           
            if(it!=map.end()) {
                it->second++;
            } else {
                map.insert(make_pair(words[i], 1));
            }
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, comparator> pq;
        for (auto it : map)
            pq.emplace(it.second, it.first);
        while (k-- > 0 && !pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }       
        return res;
    }
};
