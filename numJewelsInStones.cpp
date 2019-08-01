class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, int> umap;
        int i;
        int sum = 0;
        int Slength = S.size();
        int Jlength = J.size();
        for(i = 0; i < Slength; i++) {
            umap[S[i]]++;
        }
        for (auto x: J) {
            if (umap[x]) {
                sum+=umap[x];
            }
        }
        return sum;
    }
};
