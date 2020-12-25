class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxN = 0;
        vector<bool>res;
        for(int i = 0; i < candies.size(); ++i) {
            maxN = maxN >= candies[i] ? maxN : candies[i];
        }
        int temp;
        bool r;
        for(int i = 0; i < candies.size(); ++i) {
            temp = candies[i]+extraCandies;
            r = temp >= maxN ? true : false;
            res.push_back(r);
        }
        return res;
    }
};
