class Solution {
public:
    int hammingWeight(uint32_t n) {
        int m = bitset<32>(n).count();
        return m;
    }
};
