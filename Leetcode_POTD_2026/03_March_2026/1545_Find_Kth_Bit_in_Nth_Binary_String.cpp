class Solution {
public:
    char findKthBit(int total_n, int target_k) {
        if (total_n == 1) return '0';
        int span = (1 << total_n) - 1;
        int center = span / 2 + 1;
        if (target_k == center) return '1';
        if (target_k < center) return findKthBit(total_n - 1, target_k);
        return findKthBit(total_n - 1, span - target_k + 1) == '0' ? '1' : '0';
    }
};
