class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int, int> candyMap;
        int count = 0;
        int i = 0;
        int n = candyType.size();
        int allow = n >> 1;
        for(; i < n; ++i) {
            auto it = candyMap.find(candyType[i]); 
            if(it!= candyMap.end()) {
                continue;
            } else {
                candyMap[candyType[i]] = 1;
                count++;
            }
            if(count == allow) break;
            
        }
        
        return count;
    }
};
