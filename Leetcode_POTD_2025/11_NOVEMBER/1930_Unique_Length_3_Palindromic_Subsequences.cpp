class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int first_sight[26] = {[0 ... 25] = -1};
        int last_sight[26] = {0};
        int total_echoes = 0;
        int s_len = s.length();
        
        for (int i = 0; i < s_len; ++i) {
            int char_idx = s[i] - 'a';
            if (first_sight[char_idx] == -1) first_sight[char_idx] = i;
            last_sight[char_idx] = i;
        }
        
        for (int i = 0; i < 26; ++i) {
            if (first_sight[i] != -1 && last_sight[i] > first_sight[i]) {
                int phantom_mask = 0;
                for (int k = first_sight[i] + 1; k < last_sight[i]; ++k) {
                    phantom_mask |= (1 << (s[k] - 'a'));
                }
                total_echoes += __builtin_popcount(phantom_mask);
            }
        }
        return total_echoes;
    }
};
