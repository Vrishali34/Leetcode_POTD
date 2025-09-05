class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int ops_count = 1; ops_count <= 60; ++ops_count) {
            long long remaining = (long long)num1 - (long long)ops_count * num2;
            if (remaining >= ops_count && __builtin_popcountll(remaining) <= ops_count) {
                return ops_count;
            }
        }
        return -1;
    }
};
