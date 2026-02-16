class Solution {
public:
    int reverseBits(int n) {
        unsigned int bit_flipped = 0;
        for (int bit_idx = 0; bit_idx < 32; ++bit_idx) {
            bit_flipped = (bit_flipped << 1) | (n & 1);
            n >>= 1;
        }
        return bit_flipped;
    }
};
