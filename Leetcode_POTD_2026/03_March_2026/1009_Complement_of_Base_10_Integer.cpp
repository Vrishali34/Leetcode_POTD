class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        unsigned int bit_shield = 1;
        while (bit_shield < n) {
            bit_shield = (bit_shield << 1) | 1;
        }
        return n ^ bit_shield;
    }
};
