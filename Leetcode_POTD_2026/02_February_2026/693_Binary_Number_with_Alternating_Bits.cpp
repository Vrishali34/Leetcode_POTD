class Solution {
public:
    bool hasAlternatingBits(int n) {
        long bit_sync = n ^ (n >> 1);
        return (bit_sync & (bit_sync + 1)) == 0;
    }
};
