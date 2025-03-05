class Solution {
public:
    long long coloredCells(int z) {
        return (long long)z*z + (z-1LL)*(z-1);
    }
};
