class Solution {
public:
    int minimizeXor(int z, int y) {
        int need = __builtin_popcount(y), have = __builtin_popcount(z);
        while (need != have) {
            z += (have < need ? 1 : -1);
            have = __builtin_popcount(z);
        }
        return z;
    }
};
