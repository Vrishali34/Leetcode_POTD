class Solution {
public:
    int longestBalanced(string s) {
        int max_span = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            int char_freq[26] = {0}, unique_cnt = 0;
            for (int j = i; j < n; ++j) {
                if (char_freq[s[j] - 'a']++ == 0) unique_cnt++;
                int ref_val = char_freq[s[i] - 'a'], match_all = 1;
                for (int k = 0; k < 26; ++k) {
                    if (char_freq[k] && char_freq[k] != ref_val) {
                        match_all = 0; break;
                    }
                }
                if (match_all) max_span = max(max_span, j - i + 1);
            }
        }
        return max_span;
    }
};
