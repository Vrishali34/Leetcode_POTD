class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < (1 << k) + k - 1) return false;
        vector<bool> seen_bits(1 << k, false);
        int bit_val = 0, mask_k = (1 << k) - 1, total_hit = 0;
        for (int i = 0; i < s.size(); ++i) {
            bit_val = ((bit_val << 1) & mask_k) | (s[i] - '0');
            if (i >= k - 1 && !seen_bits[bit_val]) {
                seen_bits[bit_val] = true;
                if (++total_hit == (1 << k)) return true;
            }
        }
        return false;
    }
};
