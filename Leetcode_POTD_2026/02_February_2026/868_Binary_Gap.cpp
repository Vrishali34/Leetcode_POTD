class Solution {
public:
    int binaryGap(int n) {
        int max_span = 0, last_pos = -1, bit_idx = 0;
        while (n > 0) {
            if (n & 1) {
                if (last_pos != -1) max_span = max(max_span, bit_idx - last_pos);
                last_pos = bit_idx;
            }
            n >>= 1;
            bit_idx++;
        }
        return max_span;
    }
};
