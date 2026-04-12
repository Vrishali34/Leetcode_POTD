class Solution {
    int memo_table[301][27][27];
    int glyph_gap(int src_idx, int dest_idx) {
        if (src_idx == 26) return 0;
        return abs(src_idx / 6 - dest_idx / 6) + abs(src_idx % 6 - dest_idx % 6);
    }
    int kinetic_flow(const string& text, int char_ptr, int digit_alpha, int digit_beta) {
        if (char_ptr == text.length()) return 0;
        if (memo_table[char_ptr][digit_alpha][digit_beta] != -1) return memo_table[char_ptr][digit_alpha][digit_beta];
        int target_glyph = text[char_ptr] - 'A';
        int alpha_shift = glyph_gap(digit_alpha, target_glyph) + kinetic_flow(text, char_ptr + 1, target_glyph, digit_beta);
        int beta_shift = glyph_gap(digit_beta, target_glyph) + kinetic_flow(text, char_ptr + 1, digit_alpha, target_glyph);
        return memo_table[char_ptr][digit_alpha][digit_beta] = min(alpha_shift, beta_shift);
    }
public:
    int minimumDistance(string word) {
        memset(memo_table, -1, sizeof(memo_table));
        return kinetic_flow(word, 0, 26, 26);
    }
};
