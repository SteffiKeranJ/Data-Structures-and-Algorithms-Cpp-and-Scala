class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> bit(n);
        bitset<32> ans;
        for(int i = 0; i < 32; i++) {
            ans[i] = bit[31-i];
        }
        return ans.to_ulong();
    }
};
