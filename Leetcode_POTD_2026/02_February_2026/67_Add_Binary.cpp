class Solution {
public:
    string addBinary(string bit_a, string bit_b) {
        string res_bits = "";
        int idx_a = bit_a.size() - 1, idx_b = bit_b.size() - 1, carry_val = 0;
        while (idx_a >= 0 || idx_b >= 0 || carry_val) {
            if (idx_a >= 0) carry_val += bit_a[idx_a--] - '0';
            if (idx_b >= 0) carry_val += bit_b[idx_b--] - '0';
            res_bits += (carry_val % 2) + '0';
            carry_val /= 2;
        }
        reverse(res_bits.begin(), res_bits.end());
        return res_bits;
    }
};
